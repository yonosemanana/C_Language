#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */
	
	fahr = upper;
	while (fahr >= lower) 
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("Fahrenheit: %d\t - Celsius: %d\n", fahr, celsius);
		fahr = fahr - step;
	}
}
