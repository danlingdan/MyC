#include "hua.h"

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

// 创建新一元运算符
static Node* new_unary(NodeKind kind, Node* expr) {
	Node* node = new_node(kind);
	node->lhs = expr;
	return node;
}

// 创建新整数Node
static Node* new_num(int val) {
	Node* node = new_node(ND_NUM);
	node->val = val;
	return node;
}

// 向前声明
static Node* stmt(void);
static Node* expr(void);
static Node* equality(void);
static Node* relational(void);
static Node* add(void);
static Node* mul(void);
static Node* unary(void);
static Node* primary(void);

// program 是编译单元的顶层规则，匹配零个或多个 stmt（语句），即整个程序由一系列语句顺序组成
Node* program(void) {
	Node head = {};
	Node* cur = &head;

	while (!at_eof())
	{
		cur->next = stmt();
		cur = cur->next;
	}
	return head.next;
}

// stmt 解析语句：支持 return 表达式语句和普通表达式语句，均以分号结尾
static Node* stmt(void) {
	if (consume("return")) {
		Node* node = new_unary(ND_RETURN, expr());
		expect(";");
		return node;
	}

	Node* node = new_unary(ND_EXPR_STMT, expr());
	expect(";");
	return node;
}

// expr 是表达式的入口规则，当前直接委托给 equality 解析（即表达式的最顶层就是相等性运算）
static Node* expr(void)
{
	return equality();
}

// // equality 解析相等性表达式，以 relational 为左操作数，右侧可重复匹配 "==" 或 "!=" 连接 relational(左结合)
static Node* equality(void)
{
	Node* node = relational();

	for (;;) {
		if (consume("=="))
			node = new_binary(ND_EQ, node, relational());
		else if (consume("!="))
			node = new_binary(ND_NE, node, relational());
		else
			return node;
	}
}

// relational 解析关系表达式，以 add 为左操作数，右侧可重复匹配 "<"、"<="、">"、">=" 连接 add(左结合)
static Node* relational(void)
{
	Node* node = add();

	for (;;) {
		if (consume("<"))
			node = new_binary(ND_LT, node, add());
		else if (consume("<="))
			node = new_binary(ND_LE, node, add());
		else if (consume(">"))
			node = new_binary(ND_LT, add(), node);
		else if (consume(">="))
			node = new_binary(ND_LE, add(), node);
		else
			return node;
	}

}

// add 解析加减法表达式，以 mul 为左操作数，右侧可重复匹配 "+" 或 "-" 连接 mul(左结合)
static Node* add(void)
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

// mul 解析乘法/除法表达式，左操作数为 unary，右侧可重复匹配 "* unary" 或 "/ unary"(左结合)
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
static Node* primary(void) {
	if (consume("(")) {
		Node* node = expr();
		expect(")");
		return node;
	}

	return new_num(expect_number());
}