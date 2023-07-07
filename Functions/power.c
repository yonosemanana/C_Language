#include <stdio.h>

/* This function power(a, b) returns a^b (or a ** b) for integer a, b */

long power(int m, int n);

int main() {
	int i, n;

	n = 10;
	for (i = 0; i <= n; ++i) 
		printf("%d %ld %ld\n", i, power(2, i), power(-3, i));

	return 0;
}


/* The function returns base power p for integer base and positive integer p. */
long power (int base, int p) 
{ 	
	long res;
	int n;

	res = 1;
	for (n = 1; n <= p; ++n)
		res = res * base;
	return res;
}


