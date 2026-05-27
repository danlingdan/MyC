#include "hua.h"

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

	// 生成汇编
	codegen(node);

	return 0;
}
