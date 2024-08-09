#include <stdio.h>

#define TRUE	1
#define FALSE	0

void main() {
	char c;
	int isBlank;

	c = getchar();
	isBlank = FALSE;

	while (c != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if ( isBlank == FALSE)
				putchar('\n');
			isBlank = TRUE;	
		}
		else {
			putchar(c);
			isBlank = FALSE;
		}
		c = getchar();

	}

}
