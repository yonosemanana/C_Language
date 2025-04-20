#include <stdio.h>

#define MAXTEMP		300
#define MINTEMP		0
#define STEPTEMP	10
#define MAXCELS		150
#define MINCELS		-18

float fahr_to_cels(float fahr);

float cels_to_fahr(float cels) {
	return 9.0 / 5 * cels + 32;
}

int main() {
	float fahr, cels;

	printf("Temperature\nFahrenheit:\t Celsius:\n");
	for (fahr = MINTEMP; fahr <= MAXTEMP; fahr += STEPTEMP) {
		cels = fahr_to_cels(fahr);
		printf("%11.1f\t%9.1f\n", fahr, cels);
	}
	printf("\nCelsius:\tFahrenheit:\n");
	for (cels = MINCELS; cels <= MAXCELS; cels += STEPTEMP)
		printf("%8.1f\t%10.1f\n", cels, cels_to_fahr(cels));
	
	return 0;
}

float fahr_to_cels(float fahr) {
	float cels;

	cels = 5.0 / 9 * (fahr - 32);

	return cels;
}

