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
		printf("%d\n", len);
		entablen = entab(line, entabline);
		for (int i = 0; i < entablen; ++i)
			printf("%c", entabline[i]);

		len = getstr(line, MAXLENGTH);
	}

}

int entab(char spaceline[], char tabline[]) {
	int i = 0;
	int j = 0;
	int k, n, spaces;
	while (spaceline[i] != '\0') {
		
		if (spaceline[i] != ' ') {
			tabline[j] = spaceline[i];
			++i;
			++j;
			spaces = 0;
		}
		else {
			spaces += 1;

			if (spaces > 1 && i % TAB == 0)
				tabline[j] = '\t';
			++i;
			++j;
		}

	}

	return j;
}
