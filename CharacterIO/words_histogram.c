#include <stdio.h>

#define MAX_WORD_LENGTH	256

/* This program prints a histogram of lengths of words in input */


main() {
	char c;
	int word_length, i, j;
	int words_lengths[MAX_WORD_LENGTH - 1];
	
	word_length = 0;
	for (i = 0; i < MAX_WORD_LENGTH; ++i)
		words_lengths[i] = 0;


	while ((c = getchar()) != EOF) {
		if ( !(c == ' ' || c == '\n' || c == '\t') )
			++word_length;
		else if (word_length > 0) {
			++words_lengths[word_length];
			word_length = 0;
		}
	}	

	for (i = 0; i < MAX_WORD_LENGTH; ++i) {
		if (words_lengths[i] != 0) {
			printf("%3d: %d\t", i, words_lengths[i]);
			for (j = 0; j < words_lengths[i]; ++j)
				printf("#");
			printf("\n");
		}
	}
}
