#include "include/hua.h"

int main(int argc, char** argv) {

	// 检查参数数量
	if (argc != 2) {
		fprintf(stderr, "%s: 无效的数字参数\n", argv[0]);
		return 1;
	}

	// 准备token分词和解析
	user_input = argv[1];
	token = tokenize();
	Function* prog = program();

	// 为本地变量分配偏移量
	int offset = 0;
	for (Var* var = prog->locals; var; var = var->next) {
		// 简单起见直接分配8字节
		offset += 8;
		var->offset = offset;
	}
	prog->stack_size = offset;

	// 生成汇编
	codegen(prog);

	return 0;
}
