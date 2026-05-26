#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {

	// 检查参数数量
	if (argc != 2) {
		fprintf(stderr, "%s: 无效的数字参数\n", argv[0]);
		return 1;
	}

	// 获取输入参数
	char* p = argv[1];

	// 输出汇编代码
	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main: \n");
	printf("mov rax,%ld\n", strtol(p, NULL, 10));

	// 实现加(+)和减(-)运算
	while (*p)
	{
		// 如果是加号(+)
		if (*p == '+') {
			p++;
			printf("  add rax,%ld\n", strtol(p, &p, 10));
			continue;
		}

		// 如果是减号(-)
		if (*p == '-') {
			p++;
			printf("  sub rax,%ld\n", strtol(p, &p, 10));
			continue;
		}

		// 没有匹配的符号
		fprintf(stderr, "未知的符号:'%c'\n", *p);
		return 1;
	}

	printf("  ret\n");

	return 0;
}