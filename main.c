#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	if (token->kind != TK_RESERVED || token->str[0] != op)
		return false;
	// 遍历下一个token
	token = token->next;
	return true;
}

// 确保当前的token为op
void except(char op) {
	if (token->kind != TK_RESERVED || token->str[0] != op)
		error_at(token->str, "excepted '%c'", op);
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
Token* new_token(TokenKind kind, Token* cur, char* str) {
	Token* tok = calloc(1, sizeof(Token));
	tok->str = str;
	tok->kind = kind;
	cur->next = tok;
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

		// 运算符
		if (*p == '+' || *p == '-') {
			cur = new_token(TK_RESERVED, cur, p++);
			continue;
		}

		// 整数字面量
		if (isdigit(*p)) {
			cur = new_token(TK_NUM, cur, p++);
			cur->val = strtol(p, &p, 10);
			continue;
		}

		// 其他未知
		error_at(p, "未知token");

	}

	// 文件结束
	new_token(TK_EOF, cur, p++);
	return head.next;
}



int main(int argc,char **argv) {

	// 检查参数数量
	if (argc != 2) {
		fprintf(stderr, "%s: 无效的数字参数\n", argv[0]);
		return 1;
	}

	// 准备token分词
	user_input = argv[1];
	token = tokenize();

	// 汇编全局变量
	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main: \n");

	// 第一个token必须为数字
	printf("mov rax,%ld\n", except_number());

	// 接下来"+ 数字"和"- 数字"
	while (!at_eof())
	{
		if (consume('+')) {
			printf("  add rax,%ld", except_number());
			continue;
		}

		
		except('-');
		printf("  sub rax,%ld", except_number());
	}
	
	// 汇编结束
	printf("  ret\n");

	return 0;
}