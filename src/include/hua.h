#pragma once
#define _GNU_SOURCE
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 声明一下垃圾微软没支持的C标准函数

/**
 * @brief 复制源字符串的前 size 个字节，并保证结果以空字符结尾。
 *
 * 该函数从 src 指向的以空字符结尾的字节串中复制至多 size 个字节，
 * 并在新分配的内存末尾追加一个空字符（'\0'）。新字符串的内存通过
 * malloc() 获得，调用者有责任在不再需要时调用 free() 释放它。
 *
 * @param src   指向源空结尾字节串的指针。
 * @param size  最多从 src 复制的字节数（不包括结尾的空字符）。
 *
 * @warning 返回的指针必须通过 free() 释放，否则会造成内存泄漏。
 *
 * @return 指向新分配字符串的指针，该字符串包含 src 的前 size 个字符
 *         （若不足 size 则以整个 src 为准），并总是以空字符结尾。
 *         如果发生错误（例如内存分配失败），则返回空指针，并且可能
 *         设置 errno 以指示错误原因。
 */
extern char* strndup(const char* src, size_t size);

//
// tokenize.c
//

/* 分词器 */
// Token种类枚举
typedef enum {
	TK_RESERVED, // 关键字或标点符
	TK_IDENT, // 标识符
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
Token* consume_ident(void);
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

// 本地变量
typedef struct Var Var;
struct Var
{
	Var* next;
	char* name; // 变量名
	int offset; // 以RBP为基准的偏移
};

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
	ND_ASSIGN, // 赋值
	ND_RETURN, // 返回
	ND_IF, // IF
	ND_WHILE, // WHILE
	ND_FOR, // FOR
	ND_EXPR_STMT, // 表达式语句
	ND_VAR, // 变量
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

	// if或 while 或for语句
	Node* cond; // 条件
	Node* then; // 条件为真时语句
	Node* els; // 否则
	Node* init; // 初始化表达式
	Node* inc; // 递增/更新表达式

	Var* var; // 如果为变量则有用
	long val; // 如果为整数枚举则有使用
};

// 函数定义
typedef struct Function Function;
struct Function
{
	Node* node;
	Var* locals;
	int stack_size;
};

Function* program(void);

//
// codegen.c
//

void codegen(Function* prog);

