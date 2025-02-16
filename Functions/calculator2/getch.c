#include <stdio.h>
#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("Error: too many characters in ungetch buffer!\n");
}

/* push string back on input */
void ungets(char s[]) {
	for (int i = 0; s[i] != '\0'; i++)
		ungetch(s[i]);
}
