#include <stdio.h>

/* This program copies input to output
 * and replaces tabs with \t, backspaces with \b and backslashes with \. */

main() {
	char c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') 
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\");
		else
			putchar(c);
	}
}



