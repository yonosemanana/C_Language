/*
 * farenheit.c
 *
 *  Created on: Apr 11, 2022
 *      Author: alper
 */


main() {
	float fahr, celsius; /* Temperature in Fahrenheits and Celsius */
	int lower, higher, step; /* lower and upper boundaries of the temperature range and step */

	lower = 0;
	higher = 300;
	step = 20;

	fahr = lower;
	printf("%s\t%s\n", "Farenheit", "Celsius");
	while (fahr <= higher) {
		celsius = (fahr - 32.0) * 5.0 / 9.0;
		printf("%9.0f\t%7.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
