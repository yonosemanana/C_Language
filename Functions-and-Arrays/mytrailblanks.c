#include <stdio.h>

#include "mystrfunc.h"


int main () {
	char nextline[MAXLENGTH];
	int len, i, j;

	len = getstr(nextline, MAXLENGTH);
	
	while (len) {
		for (i = len-2; i >= 0 && (nextline[i] == ' ' || nextline[i] == '\t'); --i)
			;
		printf("i = %d\n", i);
		for (j = 0; j <= i; ++j)
			printf("%c", nextline[j]);
		printf("\n");

		len = getstr(nextline, MAXLENGTH);
	}

	return 0;

}


