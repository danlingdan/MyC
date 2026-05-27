#pragma once
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// tokenize.c
//

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

void error(char* fmt, ...);
void error_at(char* loc, char* fmt, ...);
bool consume(char* op);
void expect(char* op);
long expect_number(void);
bool at_eof(void);
Token* tokenize(void);

extern char* user_input;
extern Token* token;

//
// parse.c
//

/* 解析器 */
// 采用递归下降
// Node枚举
typedef enum {
	ND_ADD, // 加
	ND_SUB, // 减
	ND_MUL, // 乘
	ND_DIV, // 除
	ND_EQ, // 等于
	ND_NE, // 不等于
	ND_LT, // 小于
	ND_LE, // 小于等于
	ND_RETURN, // 返回
	ND_EXPR_STMT, // 表达式语句
	ND_NUM, // 整数
} NodeKind;

// AST(抽象语法树) Node种类
typedef struct Node Node;
struct Node
{
	NodeKind kind;
	Node* next; // 下一个Node
	Node* lhs; // 左节点
	Node* rhs; // 右节点
	long val; // 如果为整数枚举则有使用
};

Node* program(void);

//
// codegen.c
//

void codegen(Node* node);

