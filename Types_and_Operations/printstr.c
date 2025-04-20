#include <stdio.h>

const int MAXLEN = 20;

void main (void) {
	int i = 0;
	char c;
	
	while ((c = getchar()) != EOF) {
		putchar(c);
		if (c == '\n')
			break;
		if (i >= MAXLEN)
			break;
		++i;
	}

}
