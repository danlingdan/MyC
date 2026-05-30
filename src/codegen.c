#include "include/hua.h"

// 文件全局变量定义
// if 或 while 或 for语句的唯一序列号
static int labelseq = 1;

/* 汇编代码生成器 */
// 将Node地址入栈
static void gen_addr(Node* node) {
	// 判断当前节点是否为变量（只有变量才有内存地址）
	if (node->kind == ND_VAR) {
		// 相对于rbp的栈偏移量
		printf("  lea rax,[rbp-%d]\n", node->var->offset); // 将变量的有效地址加载到rax寄存器
		printf("  push rax\n"); // 将计算出的变量地址压入栈顶
		return;
	}

	error("不是一个左值");
}

static void load(void) {
	printf("  pop rax\n");
	printf("  mov rax, [rax]\n"); // // 以rax中的值为指针，从内存中读取对应数据存回rax
	printf("  push rax\n"); // 将读取到的值重新压入栈顶(栈顶内容从“地址”变为“值”)
}

static void store(void) {
	printf("  pop rdi\n");
	printf("  pop rax\n");
	printf("  mov [rax], rdi\n");
	printf("  push rdi\n");
}

// 生成函数
static void gen(Node* node) {

	switch (node->kind)
	{
	case ND_NUM: // 如果是数字,压栈
		printf("  push %ld\n", node->val);
		return;
	case ND_EXPR_STMT:
		gen(node->lhs);
		printf("  add rsp,8\n"); // 清理栈空间，丢弃表达式的返回值。
		return;
	case ND_VAR:
		gen_addr(node);
		load();
		return;
	case ND_ASSIGN:
		gen_addr(node->lhs);
		gen(node->rhs);
		store();
		return;
	case ND_IF: {
		int seq = labelseq++;
		if (node->els) { // 带 else 分支的 if-else 语句
			gen(node->cond);
			printf("  pop rax\n");
			printf("  cmp rax, 0\n");
			printf("  je  .L.else.%d\n", seq);
			gen(node->then);
			printf("  jmp .L.end.%d\n", seq);
			printf(".L.else.%d:\n", seq);
			gen(node->els);
			printf(".L.end.%d:\n", seq);
		}
		else { // 不带 else 分支的 if-else 语句
			gen(node->cond);
			printf("  pop rax\n");
			printf("  cmp rax, 0\n");
			printf("  je  .L.end.%d\n", seq);
			gen(node->then);
			printf(".L.end.%d:\n", seq);
		}
		return;
	}
	case ND_WHILE:
	{
		int seq = labelseq++;
		printf(".L.begin.%d:\n", seq);
		gen(node->cond);
		printf("  pop rax\n");
		printf("  cmp rax, 0\n");
		printf("  je  .L.end.%d\n", seq);
		gen(node->then);
		printf("  jmp .L.begin.%d\n", seq);
		printf(".L.end.%d:\n", seq);
		return;
	}
	case ND_FOR:
	{
		int seq = labelseq++;
		if (node->init)
			gen(node->init);
		printf(".L.begin.%d:\n", seq);
		if (node->cond) {
			gen(node->cond);
			printf("  pop rax\n");
			printf("  cmp rax, 0\n");
			printf("  je  .L.end.%d\n", seq);
		}
		gen(node->then);
		if (node->inc)
			gen(node->inc);
		printf("  jmp .L.begin.%d\n", seq);
		printf(".L.end.%d:\n", seq);
		return;
	}
	case ND_BLOCK:
		for (Node* n = node->body; n; n = n->next)
			gen(n);
		return;
	case ND_FUNCTION:
		printf("  call %s\n", node->funcname);
		printf("  push rax\n");
		return;
	case ND_RETURN: // 如果是return语句，直接生成汇编返回
		gen(node->lhs);
		printf("  pop rax\n");
		printf("  jmp .L.return\n"); // 清理及返回逻辑,统一跳转到这个公共的返回块
		return;
	}

	// 生成左右节点代码
	gen(node->lhs);
	gen(node->rhs);

	// 出栈以给左右子树腾出寄存器空间
	printf("  pop rdi\n");
	printf("  pop rax\n");

	/* 核心约定 */
	/*
	左操作数始终存放在 rax 寄存器中。
	右操作数始终存放在 rdi 寄存器中。
	计算结果始终写回 rax 寄存器。

	sete  al	==	相等 (Equal)				ZF=1
	setne al	!=	不相等 (Not Equal)		ZF=0
	setl  al	<	小于 (Less)				SF≠OF
	setle al	<=	小于等于 (Less or Equal)	ZF=1或SF≠OF

	*/


	// 根据类型生成代码
	switch (node->kind)
	{
	case ND_ADD:
		printf("  add rax, rdi\n");
		break;
	case ND_SUB:
		printf("  sub rax, rdi\n");
		break;
	case ND_MUL:
		printf("  imul rax, rdi\n");
		break;
	case ND_DIV:
		printf("  cqo\n"); // 符号扩展
		printf("  idiv rdi\n"); // 用rdx:rax ÷ rdi，商存入 rax，余数存入 rdx
		break;
	case ND_EQ:
		printf("  cmp rax, rdi\n");
		printf("  sete al\n");
		printf("  movzb rax, al\n");
		break;
	case ND_NE:
		printf("  cmp rax, rdi\n");
		printf("  setne al\n");
		printf("  movzb rax, al\n");
		break;
	case ND_LT:
		printf("  cmp rax, rdi\n");
		printf("  setl al\n");
		printf("  movzb rax, al\n");
		break;
	case ND_LE:
		printf("  cmp rax, rdi\n");
		printf("  setle al\n");
		printf("  movzb rax, al\n");
		break;
	}

	printf("  push rax\n");
}

void codegen(Function* prog) {
	// 输出关键全局汇编代码
	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");

	// 函数入口处建立栈帧(Stack Frame)
	printf("  push rbp\n"); // 基指针压栈保存，以便函数返回时恢复
	printf("  mov rbp, rsp\n"); // 建立当前函数栈帧基准
	printf("  sub rsp, %d\n", prog->stack_size); // x86-64SystemVABI要求call指令后 rsp 必须 16字节对齐

	for (Node* n = prog->node; n; n = n->next)
		gen(n); // 生成每一段代码

	// 函数尾声(Function Epilogue)
	printf(".L.return:\n"); // 定义局部标签，作为函数内所有 return 语句的统一跳转目标
	printf("  mov rsp, rbp\n"); // 将栈指针恢复到基指针位置，一次性释放所有局部变量空间
	printf("  pop rbp\n"); // 从栈顶弹出之前保存的旧基指针，恢复调用者的栈帧基准
	printf("  ret\n");
}