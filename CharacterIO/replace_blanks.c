#include <stdio.h>
#include <stdbool.h>

/* This program copies input to output
 * and replaces string with one or more blanks with a single blank. */

main() {
	char c;
	bool blankFound;

	blankFound = false;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
			blankFound = false;
		}
		else {
			if (! blankFound)
				putchar(c);
			blankFound = true;
		}
	}
}



