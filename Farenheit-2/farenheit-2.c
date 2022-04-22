/*
 * farenheit-2.c
 *
 *  Created on: Apr 22, 2022
 *      Author: alper
 */

#include <stdio.h>

#define LOWER 0 /* Lower limit of temperature range */
#define UPPER 300 /* Upper limit of temperature range */
#define STEP 20 /* Step of temperature range */


main()
{
	float fahr;
	float celsius;
	for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
	{
		celsius = (fahr - 32.0) * 5.0 / 9.0;
		printf("%3.0f\t%6.1f\n", fahr, celsius);
	}
}
