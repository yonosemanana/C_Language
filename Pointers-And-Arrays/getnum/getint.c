#include "myfuncs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

/* Reads first integer from stdin with getch/ungetch 
 * Returns integer in *pnumber arg and return code as function's result */
int getint(int *pnumber) {
	
	char c;
	int sign;
	bool digit_found = false;

	// Skip leading spaces
	while (isspace(c = getch()))
		;

	// Check if number has minus sign
	if (c == '-')
		sign = -1;
	else
		sign = 1;


	// Read digits till the next non-digit character
	if (!(isdigit(c) || (c == '-') || (c == '+') || (c == EOF))) {
		ungetch(c);
		return 0;	// Return 0 for non-integer input
	}
	
	if ((c == '-') || (c == '+'))
		c = getch();	// Read first digit
	
	*pnumber = 0;
	while (isdigit(c)) {
		digit_found = true;
		*pnumber = *pnumber * 10 + (c - '0');
		c = getch();
	}
	*pnumber *= sign;

	if (!digit_found) {
		ungetch(c);
		return 0;	// If there was no digits (e.g. only "-" or "+" sign, return error code 0)
	}
	
	if (c != EOF)
		ungetch(c);

	return c;
}
