#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>



/* Generate random integer in range (m, n) */
int gen_rand_int(int m, int n) {
	double dm = (double) m;
	double dn = (double) n;

	//srand(time(NULL));

	return (int)(dm + (dn - dm) * (double) rand() / ((double) RAND_MAX + 1));
}

int* gen_rand_int_array(int m, int n, int len) {
	int *arr = malloc(len * sizeof(int));
	
	for (int i = 0; i < len; ++i) {
		arr[i] = gen_rand_int(m, n);
		// printf("%d\n", arr[i]);
	}
	return arr;
}
