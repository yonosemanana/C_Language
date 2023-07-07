#include <stdio.h>

/* This program counts number of lines. */

main() {
	long nl;
	char c;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%ld", nl);
}
