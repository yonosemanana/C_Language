#include <stdio.h>

void main() {
	char c;
	long nc, nw, nl;
	int isBlank;

	nc = 0;
	nw = 0;
	nl = 0;

	c = getchar();
	isBlank = 1;
	while (c != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if ((c == ' ') || (c == '\t') || (c == '\n')) {
			if (! isBlank)
				++nw;
			isBlank = 1;
		}
		else
			isBlank = 0;

		c = getchar();
	}
	printf("Number of characters: %ld\n", nc);
	printf("Number of words: %ld\n", nw);
	printf("Number of lines: %ld\n", nl);

}
