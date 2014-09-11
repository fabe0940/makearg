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

		for(; isWhitespace(*ch); ch++) {
			/* Do Nothing */
		}
	}
	argc++;

	printf("- argc:%d\n", argc);

	/* parse words */

	*args = malloc(argc * sizeof(char*));

	ch = s;
	end = s;
	for(i = 0; i < argc; i++) {
		printf("- i:%d\n", i);

		printf("- searching for whitespace...");
		for(end = ch; !isWhitespace(*end); end++) {
			/* Do Nothing */
		}
		printf("\tdone!\n");

		printf("- Setting null byte...");
		*end = '\0';
		printf("\t\tdone!\n");

		printf("- strlen(ch):%d\n", strlen(ch));

		printf("- Allocating *args[i]...");
		*args[i] = malloc((strlen(ch) + 1) * sizeof(char));
		printf("\tdone!\n");

		printf("- ch:%s\n", ch);
		printf("- end:%s\n", (end + 1));

		printf("- Copying string...");
		strcpy(*args[i], ch);
		printf("\t\tdone!\n");

		printf("- args[i]:%s\n", *args[i]);

		for(ch = (end + 1); isWhitespace(*ch); ch++) {
			/* Do Nothing */
		}

		printf("- ch:%s\n", ch);
	}

	return argc;
}
