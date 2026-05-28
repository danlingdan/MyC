#include "include/hua.h"

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
bool consume(char* op) {
	if (token->kind != TK_RESERVED || strlen(op) != token->length || strncmp(token->str, op, token->length))
		return false;
	// 遍历下一个token
	token = token->next;
	return true;
}

// 如果是一个标识符则消耗它
Token* consume_ident(void) {
	if (token->kind != TK_IDENT)
		return NULL;
	Token* t = token;
	token = token->next;
	return t;
}

// 确保当前的token为op
void expect(char* op) {
	if (token->kind != TK_RESERVED || strlen(op) != token->length || strncmp(token->str, op, token->length))
		error_at(token->str, "excepted \"%s\"", op);
	token = token->next;
}

// 确保当前token为TK_NUM
long expect_number(void) {
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

// 字符串前缀判断
bool startswith(char* p, char* q) {
	return strncmp(p, q, strlen(q)) == 0;
}

// 字符是否是字符
static bool is_alpha(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_';
}

// 字符是否是字母或数字
static bool is_alnum(char c) {
	return is_alpha(c) || ('0' <= c && c <= '9');
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

		// 关键字
		// return关键字
		if (startswith(p, "return") && !is_alnum(p[6])) {
			cur = new_token(TK_RESERVED, cur, p, 6);
			p += 6;
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

		// 标识符
		if (is_alnum(*p)) {
			char* q = p++;
			while (is_alnum(*p))
			{
				p++;
			}
			cur = new_token(TK_IDENT, cur, q, p - q);
			continue;
		}

		// 多字母标点符号
		if (startswith(p, "==") || startswith(p, "!=") || startswith(p, ">=") || startswith(p, "<=")) {
			cur = new_token(TK_RESERVED, cur, p, 2);
			p += 2;
			continue;
		}

		// 单字母标点符号
		if (ispunct(*p)) {
			cur = new_token(TK_RESERVED, cur, p++, 1);
			continue;
		}

		// 其他未知
		error_at(p, "未知token");

	}

	// 文件结束
	new_token(TK_EOF, cur, p++, 0);
	return head.next;
}