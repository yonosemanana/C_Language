#include <stdio.h>
#include <stdbool.h>

/* This program counts words, lines and characters from input. */


main() {
	long wn, ln, cn;
	char c;
	bool prevIsChar;
	
	wn = 0; ln = 0; cn = 0; 
	prevIsChar = false;
	while ((c = getchar()) != EOF) {
		
		putchar(c);
		++cn;

		if (c == '\n')
			++ln;
		if ((c == '\n') || (c == '\t') || (c == ' ')) {
			if (prevIsChar)
				++wn;
			prevIsChar = false;	
		}
		else
			prevIsChar = true;
	}
	printf("Characters number: %ld\n", cn);
	printf("Words number %ld\n", wn);
	printf("Lines number: %ld\n", ln);	
	
}
