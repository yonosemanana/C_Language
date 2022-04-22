/*
 * Celsius.c
 *
 *  Created on: Apr 21, 2022
 *      Author: alper
 */

main () {
	float fahr, celsius; /* Temperature in Fahrenheits and Celsius */
	int lower, higher, step; /* lower and upper boundaries of the temperature range and step */

	lower = -20;
	higher = 150;
	step = 10;

	celsius = lower;
	printf("%s\t%s\n", "Celsius", "Farenheit");
	while (celsius <= higher) {
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%7.2f\t%9.2f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
