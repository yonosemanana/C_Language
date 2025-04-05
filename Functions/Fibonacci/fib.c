#include <stdio.h>

/* Generate n-th Fibonacci number */
long fib(int n);

int main(void) {
	int n;
	long fib_n;
	
	printf("Enter integer n: \n");
	scanf("%d", &n);
	
	fib_n = fib(n);
	printf("Fibonacci %d-th number: %ld\n", n, fib_n);
}

/* Generate n-th Fibonacci number */
long fib(int n) {

	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (n > 2)
		return fib(n-2) + fib(n-1);
}


