#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getch.h"

#define NUMBER  '0'     /* signal that a number was found */

int getch(void);
void ungetch(int);

/* getop: get next operator or numberic operand or calculator's command */
int getop(char s[]) {
	int i, c, c2;

	/* skip leading whitespaces */
	while ((c = getch()) == ' ' || c == '\t')
		;
	i = 0;
	s[0] = c;
	s[1] = '\0';

	/* not a number */
	if (!isdigit(c) && c != '.' && c != '-') {
		if (c == EOF || c == '\n')
			return c;

		while(isalnum(s[++i] = c = getch())) 
			;
		s[i] = '\0';
		// printf("s = %s\n", s);
		
		if (strcmp(s, "+") == 0)
			return '+';
		if (strcmp(s, "*") == 0)
		    	return '*';
		if (strcmp(s, "-") == 0)
			return '-';
		if (strcmp(s, "/") == 0)
		       return '/';	
		if (strcmp(s, "print") == 0)
			return 'p';
		if (strcmp(s, "dup") == 0)
			return 'd';
		if (strcmp(s, "swap") == 0)
			return 's';
		if (strcmp(s, "clear") == 0)
			return 'c';
		if (strcmp(s, "sin") == 0)
			return 'S';
		if (strcmp(s, "cos") == 0)
			return 'C';
		if (strcmp(s, "exp") == 0)
			return 'E';
		if (strcmp(s, "pow") == 0)
			return 'P';
	}

	/* number (or "-" operator) */
	c2 = getch();
	ungetch(c2);
	if (c == '-' && !isdigit(c2) && c2 != '.')
		return c;	/* operator "-", not a negative number */

	if (isdigit(c) || c == '-') /* collect integer part */
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
