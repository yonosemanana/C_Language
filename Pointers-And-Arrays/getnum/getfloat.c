#include "myfuncs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

/* Reads first float from stdin with getch/ungetch 
 * Returs float in *pfn arg and return code as function's result */
int getfloat(double *pfn) {
	
	char c;
	int sign;
	bool digit_found = false;
	double frac, multiplier;

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
	
	*pfn = 0;
	while (isdigit(c)) {
		digit_found = true;
		*pfn = *pfn * 10 + (c - '0');
		c = getch();
	}
	*pfn *= sign;

	if (!digit_found) {
		ungetch(c);
		return 0;	// If there was no digits (e.g. only "-" or "+" sign, return error code 0)
	}

	if (c == '.') {		// Getting floating part of the number
		c = getch();
		frac = 0;
		multiplier = 10.0;
		while(isdigit(c)) {
			frac = frac + (c - '0') / multiplier;
			multiplier = multiplier * 10.0;
			c = getch();
		}
	*pfn += (sign * frac);
	}
	
	if (c != EOF)
		ungetch(c);

	return c;
}
