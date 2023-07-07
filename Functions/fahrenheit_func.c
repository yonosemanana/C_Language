#include <stdio.h>

#define MAX_TEMP	300
#define MIN_TEMP	0
#define STEP		20


/* This program converts temperature Fahrenheit - Celsius using a function */




float fahr_to_celc(float fahr);

int main() {
	
	float i;
	
	for (i = MIN_TEMP; i <= MAX_TEMP; i+=STEP)
		printf("Fahrenet: %3.1f - Celcius: %3.1f\n", i, fahr_to_celc(i));

	return 0;
}

float fahr_to_celc(float fahr) {
	
	float celc;

	celc = 5.0 / 9.0 * (fahr - 32);

	return celc;
}

