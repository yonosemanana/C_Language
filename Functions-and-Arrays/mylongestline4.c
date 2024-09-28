#include <stdio.h>

#include "mystrfunc2.h"

char maxline[MAXLENGTH];
char nextline[MAXLENGTH];
int len, maxlength, linelen;


int main () {

	maxlength = 0;
	linelen = 0;
	len = getstr();
	while (len) {
		linelen += len;
		
		if (len > maxlength || len >= MAXLENGTH-1)
			copystr();
		if (linelen > maxlength)
			maxlength = linelen;
		if (nextline[len-1] == '\n') 
			linelen = 0;
		
		len = getstr();
	}

	printf("The longest line is:\n");
	for (int i = 0; i < MAXLENGTH && maxline[i] != '\0'; ++i)
		printf("%c", maxline[i]);
	printf("\nIts length is: %d\n", maxlength);

	return 0;

}


