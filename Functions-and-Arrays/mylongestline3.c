#include <stdio.h>

#include "mystrfunc.h"



int main () {
	char maxline[MAXLENGTH];
	char nextline[MAXLENGTH];
	int len, maxlength, linelen;

	maxlength = 0;
	linelen = 0;
	len = getstr(nextline, MAXLENGTH);
	while (len) {
		linelen += len;
		//printf("%d\n", len);
		//printf("%d\n", linelen);
		//printf("%s\n", nextline);
		if (len > maxlength || len >= MAXLENGTH-1)
			copystr(nextline, maxline);
		if (linelen > maxlength)
			maxlength = linelen;
		if (nextline[len-1] == '\n') 
			linelen = 0;
		
		len = getstr(nextline, MAXLENGTH);
	}

	printf("The longest line is:\n");
	for (int i = 0; i < MAXLENGTH && maxline[i] != '\0'; ++i)
		printf("%c", maxline[i]);
	printf("\nIts length is: %d\n", maxlength);

	return 0;

}


