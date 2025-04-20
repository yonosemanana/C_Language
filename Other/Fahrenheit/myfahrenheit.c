#include <stdio.h>

void main() {

	// Declare variables type
	int temperature, max_temp;
	int step = 20;
	float celcius;

	printf("Fahrenheit\tCelcius\n");

	/* Main program loop */
	temperature = 0;
	max_temp = 300;
	while (temperature <= max_temp) {
		celcius = 5.0 / 9 * (temperature - 32);
		printf("%10d\t%7.0f\n", temperature, celcius);
		temperature += step;
	}

}
