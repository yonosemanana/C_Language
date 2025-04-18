#include <stdio.h>
#include <ctype.h>
#include "getch.h"
#define NUMBER  '0'     /* signal that a number was found */

int getch(void);
void ungetch(int);

/* getop: get next operator or numberic operand */
int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */

	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fractional part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}
