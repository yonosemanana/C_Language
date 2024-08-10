#include <stdio.h>

void main() {
	char c;
	double nl;

	c = getchar();
	while (c != EOF) {
		if (c == '\n')
			++nl;
		c = getchar();
	}

	printf("Number of lines: %.0f\n", nl);
	
}

