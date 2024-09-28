#include <stdio.h>

#include "myreverse.h"
#include "mystrfunc.h"

int main () {
	int len;
	char line[MAXLENGTH];
	char reverseline[MAXLENGTH];

	for (int i = 0; i < MAXLENGTH; ++i) {
		line[i] = ' ';
		reverseline[i] = ' ';
	}
	
	len = getstr(line, MAXLENGTH);
	while (len > 0) {
		reversestr(len, line, reverseline);
		//printf("%s\n", reverseline);
		for (int i = 0; i < len; ++i)
			printf("%c", reverseline[i]);
		printf("\n");
		
		len = getstr(line, MAXLENGTH);

	}

	return 0;
}

