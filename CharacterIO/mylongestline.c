#include <stdio.h>

#define MAXLENGTH	1000

int getstr(char str[], int limit);

void copystr (char str_from[], char str_to[]);

int main () {
	char maxline[MAXLENGTH];
	char nextline[MAXLENGTH];
	int len, maxlength;

	maxlength = 0;
	len = getstr(nextline, MAXLENGTH);
	while (len) {
		if (len > maxlength) {
			copystr(nextline, maxline);
			maxlength = len;
		}

		len = getstr(nextline, MAXLENGTH);
	}

	printf("The longest line is:\n");
	for (int i = 0; i < MAXLENGTH && maxline[i] != '\0'; ++i)
		printf("%c", maxline[i]);
	printf("\nIt's length is: %d\n", maxlength);

	return 0;

}


int getstr (char line[], int lim) {
	char c;
	int i;

	i = 0;
	c = getchar();
	while (c != EOF && c != '\n' && i < lim-1 ) {
		line[i] = c;
		++i;
		c = getchar();
	}
	if (c == '\n') {
		line[i] = c; ++i;
		line[i] = '\0';
		return i;
	}
	else if (c == EOF || i == lim-1) {
		line[i] = '\0'; 
		return i;
	}
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
