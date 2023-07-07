#include <stdio.h>

/* This program reads input and prints it to output one word per line. */

#define IS_SPACE	1
#define ISNOT_SPACE	0

main() {
	char c;
	int lastChar;
	
	lastChar = ISNOT_SPACE;
	while((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\n') || (c == '\t')) {
			if (lastChar == ISNOT_SPACE)
				putchar('\n');
			lastChar = IS_SPACE;	
		}
		else {
			lastChar = ISNOT_SPACE;
			putchar(c);
		}
	}	


}
