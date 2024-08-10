#include <stdio.h>

void main () {
	int ndig[10];
	char c;
	int nblank, nother, i;

	nblank = nother = 0;
	for (i = 0; i < 10; ++i)
		ndig[i] = 0;

	c = getchar();
	while (c != EOF) {
		if (c == ' ' || c == '\t' || c == '\n')
			++nblank;
		else {
			if (c > '0' && c <= '9')
				++ndig[c - '0'];
			else
				++nother;
		}

		c = getchar();
	}

	for (i = 0; i < 10; ++i)
		printf("Number of digits %d: %d\n", i, ndig[i]);
	printf("Number of blanks: %d\n", nblank);
	printf("Number of other symbols: %d\n", nother);

}
