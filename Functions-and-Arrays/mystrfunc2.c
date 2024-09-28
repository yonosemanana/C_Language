#include <stdio.h>

#define MAXLENGTH	1000


int getstr (void) {
	char c;
	int i;
	extern char nextline[MAXLENGTH];

	i = 0;
	c = getchar();
	while (c != EOF && c != '\n' && i < MAXLENGTH-2 ) {
		nextline[i] = c;
		++i;
		c = getchar();
	}
	if (c != EOF) {
		nextline[i] = c; 
		++i;
	}

	nextline[i] = '\0';
	return i;
}

void copystr (void) {
	int i;
	extern char maxline[MAXLENGTH];
	extern char nextline[MAXLENGTH];

	i = 0;
	while (nextline[i] != '\0') {
		maxline[i] = nextline[i];
		++i;	
	}
	maxline[i] = '\0';

}
