#include <limits.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "myrandint.h"

#define	N	1000

#define F_OUT	"rand_int_array.txt"

void main (void) {

	/* Test code segment
	int x;

	printf("INT_MAX = %d\n", INT_MAX);
	printf("INT_MIN = %d\n", INT_MIN);

	printf("RAND_MAX = %d\n", RAND_MAX);

	srand(time(NULL));
	x = (int) (INT_MIN + 2 * (double)INT_MAX * (double)rand() / ((double)RAND_MAX + 1));
	printf("Random number x = %d\n", x); */


	// printf("Random number x = %d\n", gen_rand_int(INT_MIN, INT_MAX));
	// printf("Random number y = %d\n", gen_rand_int(-100, 200));
	

	/* int n = 100;
	int *arr = gen_rand_int_array(-100, 200, n);

	for (int i = 0; i < n-1; ++i)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[n-1]); */

	
	FILE *fptr;
	int *arr;
	
	srand(time(NULL));	
	fptr = fopen(F_OUT, "w");
	
	arr = gen_rand_int_array(INT_MIN, INT_MAX, N);
	for (int i = 0; i < N; ++i)
		fprintf(fptr, "%d ", arr[i]);
	fclose(fptr);
}

