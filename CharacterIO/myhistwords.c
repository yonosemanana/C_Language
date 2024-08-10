#include <stdio.h>

#define MAXLENGTH	30

void main() {
	char c;
	int words[MAXLENGTH]; // Array, indexes - lengths of words, values - number of words of such length
	int i, wordl;

	for (i = 0; i < MAXLENGTH; ++i)
		words[i] = 0;
	
	wordl = 0;
	c = getchar();
	while (c != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (wordl) {
				++words[wordl];
				wordl = 0;
			}
		}
		else {
			++wordl;
		}

		c = getchar();
	}

	printf("Histogram of words lentghs\n");
	for (i = 0; i < MAXLENGTH; ++i) { 
		printf("Words of length %2d: %3d\t", i, words[i]);
		for (int j = 0; j < words[i]; ++j)
			printf("#");
		printf("\n");
	}
	
}
