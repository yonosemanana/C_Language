#include <stdio.h>

/* Convert temperature from Celsius to Fahrenheit */

void main() {
	float fahr, celsius = 0, step = 6.667;
	int upper = 149;

	printf("Celsius\tFahrenheit\n");

	for (; celsius < upper; celsius += step) {
		fahr = 9.0 / 5.0 * celsius + 32;
		printf("%7.2f\t%10.1f\n", celsius, fahr);
	}
	
}
