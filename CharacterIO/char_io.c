#include <stdio.h>

/* This program gets input from STDIN and prints character by character on STDOUT */

main()
{	char c;
	c = getchar();
	
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
