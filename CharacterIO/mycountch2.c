#include <stdio.h>

void main() {
	char c;
	long n;

	for (n = 0; getchar() != EOF; ++n)
		;

	printf("Number of characters: %ld\n", n);
	
}
