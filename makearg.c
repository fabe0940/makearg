#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "makearg.h"

int  isWhitespace(char ch) {
	int res;

	switch(ch) {
		case ' ':
		case '\t':
		case '\n':
			res = 1;
			break;
		default:
			res = 0;
	}

	return res;
}

int makearg(char* s, char*** args) {
	int i;
	int argc;
	char* ch;
	char* end;

	/* count words */

	argc = 0;
	for(ch = s; *ch != '\0'; ch++) {
		argc += isWhitespace(*ch);
	}
	argc++;

	printf("- argc:%d\n", argc);

	/* parse words */

	*args = malloc(argc * sizeof(char*));

	ch = s;
	end = s;
	for(i = 0; i < argc; i++) {
		printf("%d\n", i);

		for(end = ch; !isWhitespace(*end); end++) {
			/* Do Nothing */
		}
		*end = '\0';

		*args[i] = malloc((strlen(ch) + 1) * sizeof(char));
		printf("- %s\n", ch);
		strcpy(*args[i], ch);

		ch = end + 1;
		for(ch = end; isWhitespace(*ch); ch++) {
			/* Do Nothing */
		}
	}

	return argc;
}
