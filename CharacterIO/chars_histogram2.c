#include <stdio.h>

#define ASCII_LENGTH	256

/* This program prints a histogram of character frequencies in input */


main() {
	char c;
	int i, j;
	int characters[ASCII_LENGTH - 1];
	
	for (i = 0; i < ASCII_LENGTH; ++i)
		characters[i] = 0;


	while ((c = getchar()) != EOF) 
		++characters[c];
		

	for (i = 0; i < ASCII_LENGTH; ++i) {
		if (characters[i] != 0) {
			if (i == ' ') 
				printf("\' \' - %d: %d ", i, characters[i]);
			else if (i == '\t') 
				printf("\\t - %d: %d ", i, characters[i]);
			else if (i == '\n') 
				printf("\\n - %d: %d ", i, characters[i]);
			else
				printf("%c - %d: %d ", i, i, characters[i]);
			
			for (j = 0; j < characters[i]; ++j)
				printf("#");
			printf("\n");
		}
	}
	// printf("\\n");
	// printf("\\t");
	// printf("' '");
}