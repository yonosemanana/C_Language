#include <stdio.h>

#include "mystrfunc.h"

#define TAB	5

int detab(char tabline[], char spaceline[]);

int main(void) {
	int len, detablen;
	char line[MAXLENGTH];
	char detabline[MAXLENGTH];

	len = getstr(line, MAXLENGTH);
	while (len > 0) {
		// printf("%d\n", len);
		detablen = detab(line, detabline);
		for (int i = 0; i < detablen; ++i)
			printf("%c", detabline[i]);

		len = getstr(line, MAXLENGTH);
	}

}

int detab(char tabline[], char spaceline[]) {
	int i = 0; // Array counter for tabline[]
	int j = 0; // Array counter for spaceline[]
	int n; // number of symbols left to the next tab position
	int k; // variable for loop when adding spaces
	while (tabline[i] != '\0') {
		
		if (tabline[i] != '\t') {
			spaceline[j] = tabline[i];
			++i;
			++j;
		}
		else {
			n = TAB - j % TAB;
			// printf("%d\n", n);
			/*if (n == 0)
				n = TAB;*/
			for (k = 0; k < n; ++k) {
				spaceline[j + k] = '#';
			}
			++i;
			j = j+k;
		}

	}

	return j;
}
