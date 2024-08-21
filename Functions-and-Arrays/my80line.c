#include <stdio.h>

#include "mystrfunc.h"

#define LINELEN		80

int main () {
	char nextline[MAXLENGTH];
	int len;

	len = getstr(nextline, MAXLENGTH);
	
	while (len) {
		if (len >= LINELEN) {
			printf("%s", nextline);
		}

		len = getstr(nextline, MAXLENGTH);
	}

	return 0;

}


