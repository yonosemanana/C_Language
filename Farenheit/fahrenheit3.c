#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

main()
{
	int fahr;
	float celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;
	while (fahr <= upper)
       	{
		celsius = 5.0 / 9 * (fahr - 32);
		printf("%3d\t%6.1f\n",fahr, celsius);
		fahr = fahr + step;
	}
}
