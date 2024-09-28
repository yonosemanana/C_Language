#include <stdio.h>

#define MAXLENGTH	1000


int getstr (char line[], int lim) {
	char c;
	int i;

	i = 0;
	c = getchar();
	while (c != EOF && c != '\n' && i < lim-2 ) {
		line[i] = c;
		++i;
		c = getchar();
	}
	if (c != EOF) {
		line[i] = c; 
		++i;
	}

	line[i] = '\0';
	return i;
}

void copystr (char str_from[], char str_to[]) {
	int i;

	i = 0;
	while (str_from[i] != '\0') {
		str_to[i] = str_from[i];
		++i;	
	}
	str_to[i] = '\0';

}
