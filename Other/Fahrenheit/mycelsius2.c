#include <stdio.h>

#define LOWER	0
#define	UPPER	150
#define STEP	6.667

/* Convert temperature from Celsius to Fahrenheit */

void main() {
	float fahr, celsius;

	printf("Celsius\tFahrenheit\n");

	for (celsius = UPPER; celsius > LOWER; celsius -= STEP) {
		fahr = 9.0 / 5.0 * celsius + 32;
		printf("%7.2f\t%10.1f\n", celsius, fahr);
	}
	
}
