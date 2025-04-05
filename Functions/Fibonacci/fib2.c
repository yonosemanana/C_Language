#include <stdio.h>
#define	MAXLEN	10000

static long fib_arr[MAXLEN];

/* Generate n-th Fibonacci number */
long fib(int n);

/* Generate first 2 Fibonacci numbers to initialize storage */
static void fib_init(long fib_arr[]);

int main(void) {
	int n;
	long fib_n;
	
	printf("Enter integer n: \n");
	scanf("%d", &n);
	
	fib_n = fib(n);
	printf("Fibonacci %d-th number: %ld\n", n, fib_n);
}

/* Generate first 2 Fibonacci numbers to initialize storage */
void fib_init(long fib_arr[]) {
	fib_arr[0] = 1;
	fib_arr[1] = 1;
}

/* Generate n-th Fibonacci number */
long fib(int n) {

	/* Initialize first 2 numbers in array with Fibonacci numbers */
	fib_init(fib_arr);

	for (int i = 2; i < n; ++i) {
		fib_arr[i] = fib_arr[i-2] + fib_arr[i-1];
	}
	return fib_arr[n-1];
}


