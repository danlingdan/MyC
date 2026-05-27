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

// 创建新整数Node
static Node* new_num(int val) {
	Node* node = new_node(ND_NUM);
	node->val = val;
	return node;
}

// expr 是语法的顶层入口，当前直接委托给 equality 解析（预留扩展赋值等更低优先级运算符的位置）
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
static Node* primary(void)
{
	if (consume("(")) {
		Node* node = expr();
		except(")");
		return node;
	}

	return new_num(except_number());
}