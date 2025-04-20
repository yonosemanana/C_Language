#include <stdio.h>

/* This program version uses "for" cycle
 * to print Fahrenheit - Celsius table */

#define UPPER	300
#define LOWER	0
#define STEP	20


main ()
{	int fahr;

	for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
		printf("%3d\t%6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
}
