#include <stdio.h>

/* This program counts digits, whitespaces and other characters */

main () {
	char c;
	int nwhite, nother, i;
	int ndigits[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigits[i] = 0;

	while ((c = getchar()) != EOF) {
		if ( c >= '0' && c <= '9')
			++ndigits[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}

	printf("Digits:\n");
	for (i = 0; i < 10; ++i)
		printf("%d: %d\n", i, ndigits[i]);
	printf("Whitespaces: %d\n", nwhite);
	printf("Other characters: %d\n", nother);

}
