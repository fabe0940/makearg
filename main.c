#include <stdio.h>
#include <stdlib.h>
#include "makearg.h"

int main(int argc, char** argv) {
	int i;
	int num;
	char** strL;

	if(argc != 2) {
		printf("usage: %s <string>\n", argv[0]);
		exit(0);
	}

	num = makearg(argv[1], &strL);

	/*
	for(i = 0; i < num; i++) {
		printf("%s\n", strL[i]);
	}
	*/

	exit(0);
}
