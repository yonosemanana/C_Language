#include <stdio.h>

/* This program gets input from STDIN and prints character by character on STDOUT */

main()
{	char c;
	
	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
