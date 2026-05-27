#include "hua.h"

/* 汇编代码生成器 */
// 生成函数
static void gen(Node* node) {
	// 如果是数字,压栈
	if (node->kind == ND_NUM) {
		printf("  push %ld\n", node->val);
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
		printf("  cmp rax,rdi\n");
		printf("  sete al\n");
		printf("  movzb rax,al\n");
		break;
	case ND_LE:
		printf("  cmp rax, rdi\n");
		printf("  setne al\n");
		printf("  movzb rax, al\n");
		break;
	case ND_LT:
		printf("  cmp rax, rdi\n");
		printf("  setl al\n");
		printf("  movzb rax, al\n");
		break;
	case ND_NE:
		printf("  cmp rax, rdi\n");
		printf("  setle al\n");
		printf("  movzb rax, al\n");
		break;
	}

	printf("  push rax\n");
}

void codegen(Node* node) {
	// 输出关键全局汇编代码
	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");

	gen(node);

	for (Node* n = node; n; n = n->next) {
		// 生成每一段代码
		gen(n);
		// 结果必须在栈顶,出栈到rax来拿到退出码
		printf("  pop rax\n");
	}
	
	// 汇编结束
	printf("  ret\n");
}