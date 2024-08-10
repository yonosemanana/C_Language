#include <stdio.h>

void main() {

	// Declare variables type
	int fahr = 0, max_temp = 300, step = 20;
	int celcius;

	printf("Fahrenheit\tCelcius\n");

	/* Main program loop */
	while ( fahr <= max_temp) {
		celcius = 5.0 / 9 * (fahr - 32);
		printf("%10d\t%7.0d\n", fahr, celcius);
		fahr += step;
	}

}
