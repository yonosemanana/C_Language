#include <stdio.h>

/* Count digits, whitespaces and other symbols */
void main () {
	char c;
	int ndigits[10];
	int nwhite = 0;
	int nother = 0;

	for (int i = 0; i < 10; ++i)
		ndigits[i] = 0;

	c = getchar();
	while (c != EOF) {
		switch(c) {
		case ' ':
		case '\t':
		case '\n':
			++nwhite;
			break;
		case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9': case '0':
			++ndigits[c - '0'];
			break;
		default:
			++nother;
			break;
		}

		c = getchar();
	}

	for (int i = 0; i < 10; ++i)
		printf("ndigits[%d] = %d\n", i, ndigits[i]);
	printf("nwhite = %d\n", nwhite);
	printf("nother = %d\n", nother);

}
