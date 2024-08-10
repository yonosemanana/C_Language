#include <stdio.h>

void main() {
	char c;
	int isBlank;

	c = getchar();
	if (c == ' ')
		isBlank = 1;
	else
		isBlank = 0;

	while (c != EOF) {
		if (c == ' ') {
			if (! isBlank)
				putchar(c);
			isBlank = 1;
		}
		else {
			isBlank = 0;
			putchar(c);
		}
		c = getchar();

	}


}
