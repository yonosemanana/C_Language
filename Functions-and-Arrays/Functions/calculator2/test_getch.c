#include <stdio.h>
#include "getch.h"
#define	MAXLEN		100
#define	ESC		27


int main(void) {
	int c;
	char s[] = "Hello, world!\n";

	ungets(s);
	while ((c = getch()) != EOF ) 
		putchar(c);
	
	ungets("Another string!\n");
	//ungetch(EOF);
	ungets("Let's continue\n");
	while ((c = getch()) != EOF)
		putchar(c);


	return 0;
}
