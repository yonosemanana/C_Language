#include <stdio.h>
#include "stringfuncs.h"

#define	MAXLINE	1000	// Maximum input line length

char pattern[] = "ould";	// pattern to search for

/* find all lines matching pattern */
int main(void) {
	char line[MAXLINE];
	int found = 0;

	while (mygetline(line, MAXLINE) > 0) {
		// printf("%s", line);
		// printf("%d\n", strindex(line, pattern));
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
}

