#include <stdio.h>

/* This program counts characters from input */

main () {
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld", nc);
}
