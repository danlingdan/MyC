#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 分词器 */
// Token种类枚举
typedef enum {
	TK_RESERVED, // 关键字或标点符
	TK_NUM, // 整数字面量
	TK_EOF, // EOF标记
} TokenKind;

// Token结构体
typedef struct Token Token;
struct Token {
	TokenKind kind; // Tkoen种类
	Token* next; // 下一个Token
	long val; // 如果是TK_NUM,那么这是它的值
	char* str; // Token字符串
	int length; // Token长度
};

// 输入程序
char* user_input;

// 当前token
Token* token;

// 报告一个错误然后退出
void error(char* fmt, ...) {
	va_list ap; // 声明va_list变量，用于遍历可变参数列表
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap); // 将格式化内容输出到 stderr
	fprintf(stderr, "\n"); // 向 stderr 追加一个换行符
	exit(1);
}

// 报告错误且带有位置
void error_at(char* loc, char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);

	int pos = loc - user_input;
	fprintf(stderr, "%s\n", user_input);
	fprintf(stderr, "%*s\n", pos, ""); // 输出位置空间
	fprintf(stderr, "^ ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	exit(1);
}

// 如果当前标记与 `op` 匹配，消耗它
bool consume(char op) {
	if (token->kind != TK_RESERVED || strlen(op) != token->length || strncmp(token->str, op, token->length))
		return false;
	// 遍历下一个token
	token = token->next;
	return true;
}

// 确保当前的token为op
void except(char op) {
	if (token->kind != TK_RESERVED || strlen(op) != token->length || strncmp(token->str, op, token->length))
		error_at(token->str, "excepted \"%s\"", op);
	token = token->next;
}

// 确保当前token为TK_NUM
long except_number(void) {
	if (token->kind != TK_NUM)
		error_at(token->str, "excepted 一个数字");
	long val = token->val;
	token = token->next;
	return val;
}

// 测试文件是否到EOF处
bool at_eof(void) {
	return token->kind == TK_EOF;
}

// 添加一个新的Token然后放入token链表中
Token* new_token(TokenKind kind, Token* cur, char* str, int len) {
	Token* tok = calloc(1, sizeof(Token));
	tok->str = str;
	tok->kind = kind;
	tok->length = len;
	cur->next = tok;
	return tok;
}

// 对用户输入进行分词返回新的tokens
Token* tokenize(void) {
	char* p = user_input;
	Token head = {};
	Token* cur = &head;

	while (*p)
	{
		// 跳过空白字符
		if (isspace(*p)) {
			p++;
			continue;
		}

		// 单字母标点符号
		if (ispunct(*p)) {
			cur = new_token(TK_RESERVED, cur, p++, 1);
			continue;
		}

		// 整数字面量
		if (isdigit(*p)) {
			cur = new_token(TK_NUM, cur, p, 0);
			char* q = p;
			cur->val = strtol(p, &p, 10);
			cur->length = p - q;
			continue;
		}

		// 其他未知
		error_at(p, "未知token");

	}

	// 文件结束
	new_token(TK_EOF, cur, p++, 0);
	return head.next;
}

/* 解析器 */
// 采用递归下降
// Node枚举
typedef enum {
	ND_ADD, // 加
	ND_SUB, // 减
	ND_MUL, // 乘
	ND_DIV, // 除
	ND_NUM, // 整数
} NodeKind;

// AST(抽象语法树) Node种类
typedef struct Node Node;
struct Node
{
	NodeKind kind;
	Node* lhs; // 左节点
	Node* rhs; // 右节点
	long val; // 如果为整数枚举则有使用
};

// 创建新Node
static Node* new_node(NodeKind kind) {
	Node* node = calloc(1, sizeof(Node));
	node->kind = kind;
	return node;
}

// 创建二分树Node
static Node* new_binary(NodeKind kind, Node* lhs, Node* rhs) {
	Node* node = new_node(kind);
	node->lhs = lhs;
	node->rhs = rhs;
	return node;
}

// 创建新整数Node
static Node* new_num(int val) {
	Node* node = new_node(ND_NUM);
	node->val = val;
	return node;
}

//向前声明
static Node* expr(void);
static Node* mul(void);
static Node* unary(void);
static Node* primary(void);

// 一个表达式（expr）由一个乘法项（mul）开头，后面可以跟零个或多个“加/减号 + 乘法项”的组合。
static Node* expr(void)
{
	Node* node = mul();

	for (;;) {
		if (consume("+"))
			node = new_binary(ND_ADD, node, mul());
		else if (consume("-"))
			node = new_binary(ND_SUB, node, mul());
		else
			return node;
	}
}

// mul 解析乘法/除法表达式，左操作数为 unary，右侧可重复匹配 "* unary" 或 "/ unary"（左结合）
static Node* mul(void)
{
	Node* node = unary();

	for (;;) {
		if (consume("*"))
			node = new_binary(ND_MUL, node, unary());
		else if (consume("/"))
			node = new_binary(ND_DIV, node, unary());
		else
			return node;
	}
}

// unary 解析一元表达式：可选的前置 "+" 或 "-" 后递归跟随 unary，否则回退到 primary 解析原子单元
static Node* unary(void) {
	if (consume("+"))
		return unary();
	if (consume("-"))
		return new_binary(ND_SUB, new_num(0), unary());
	return primary();
}

// 最底层原子单元(mainly符号如括号数字等)
static Node* primary(void)
{
	if (consume("(")) {
		Node* node = expr();
		except(")");
		return node;
	}

	return new_num(except_number());
}

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
	}

	printf("  push rax\n");
}



int main(int argc,char **argv) {

	// 检查参数数量
	if (argc != 2) {
		fprintf(stderr, "%s: 无效的数字参数\n", argv[0]);
		return 1;
	}

	// 准备token分词和解析
	user_input = argv[1];
	token = tokenize();
	Node* node = expr();

	// 输出关键全局汇编代码
	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main: \n");

	// 遍历AST以生成汇编
	gen(node);
	
	// 结果必须在栈顶,出栈到rax来拿到程序退出码
	printf(" pop rax\n");
	// 汇编结束
	printf("  ret\n");

	return 0;
}
