#include <stdio.h>

#define ASCIILENGTH	128

void main() {
	char c;
	int chars[ASCIILENGTH]; // Array, indexes - ASCII characters, values - number of words of such length
	int i;

	for (i = 0; i < ASCIILENGTH; ++i)
		chars[i] = 0;

	c = getchar();
	while (c != EOF) {
		++chars[c];
		c = getchar();
	}

	printf("Histogram of char frequences\n");
	for (i = 0; i < ASCIILENGTH; ++i) { 
		printf("Char %c: %3d\t", i, chars[i]);
		for (int j = 0; j < chars[i]; ++j)
			printf("#");
		printf("\n");
	}
	
}
