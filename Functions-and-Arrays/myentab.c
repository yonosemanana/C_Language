#include <stdio.h>

#include "mystrfunc.h"

#define TAB	5

int entab(char spaceline[], char tabline[]);

int main(void) {
	int len, entablen;
	char line[MAXLENGTH];
	char entabline[MAXLENGTH];

	len = getstr(line, MAXLENGTH);
	while (len > 0) {
		// printf("%d\n", len);
		entablen = entab(line, entabline);
		for (int i = 0; i < entablen; ++i)
			printf("%c", entabline[i]);

		len = getstr(line, MAXLENGTH);
	}

}

int entab(char spaceline[], char tabline[]) {
	int i = 0; // Array counter for spaceline[]
	int j = 0; // Array counter for tabline[]
	int spaces = 0; // Number of consequitive spaces before the next tab stop
	int k, n;
	while (spaceline[i] != '\0') {
		
		if (spaceline[i] != ' ') {
			if (spaces > 0) 
				for (k = 0; k < spaces; ++k) 
					tabline[j+k] = '#';
				j = j + spaces;
			spaces = 0;
			tabline[j] = spaceline[i];
			++i;
			++j;
		}
		else {
			spaces += 1;
			if ((i+1) % TAB == 0) {
				if (spaces > 1) 
					tabline[j] = '\t';
				else 
					tabline[j] = '#';
				++j;
				spaces = 0;
			}
			++i;
		}

	}

	return j;
}
