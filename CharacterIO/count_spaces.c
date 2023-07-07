#include <stdio.h>

/* This program counts blanks, tabs and newlines. */

main()
{
	long bn, tn, ln;
	char c;

	bn = 0;
	tn = 0;
	ln = 0;
	
	while ((c = getchar()) != EOF)
		if (c == ' ')
			++bn;
		else if (c == '\t')
			++tn;
		else if (c == '\n')
			++ln;
	printf("Number of blanks: %ld\n", bn);
	printf("Number of tabs: %ld\n", tn);
	printf("Number of newlines: %ld\n", ln);
}
			
