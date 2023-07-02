#include <stdio.h>

/* print Celsius-Fahrenheit table
 * for celsius = -100, -80, ..., 200 */

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -100;	/* lower limit of temperature */
	upper = 200;	/* upper limit */
	step = 20;	/* step size */

	printf("%10s\t%8s\n", "Celsius", "Fahrenheit");

	celsius = lower;
	while (celsius <= upper)
       	{
		fahr = 9.0 / 5.0 * celsius + 32;
		printf("%10.1f\t%8.1f\n",celsius, fahr);
		celsius = celsius + step;
	}
}
