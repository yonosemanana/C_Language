#include <stdio.h>

void main() {
	char c;
	long n;

	n = 0;

	while ( getchar() != EOF)
		++n;

	printf("Number of characters: %ld\n", n);
	
}
