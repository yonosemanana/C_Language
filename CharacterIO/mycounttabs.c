#include <stdio.h>

void main() {
	char c;
	int nb, nt, nl;

	nb = 0;
	nt = 0;
	nl = 0;

	c = getchar();
	while (c != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
		c = getchar();
	}
	printf("Number of blanks: %d\n", nb);
	printf("Number of tabs: %d\n", nt);
	printf("Number of lines: %d\n", nl);
}
