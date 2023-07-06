#include <stdio.h>

main ()
{
	char c;

	while (c = getchar() != EOF) {
		// printf(c);
		// putchar(1);
		// printf(1);
		printf("%d",c);
		putchar(c);
	}
	printf("%d",c);
}
