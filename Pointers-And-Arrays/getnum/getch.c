#include <stdio.h>

#define BUFSIZE	1000

static char buffer[BUFSIZE]; // Buffer for getchar() and putchar() symbols in form of stack
static int sp = 0; // Stack pointer. Points to the next available slot in the buffer

char getch(void) {
	if ( sp > 0)
		return buffer[--sp];
	else
		return getchar();

}

void ungetch (char c) {
	buffer[sp++] = c;
}
