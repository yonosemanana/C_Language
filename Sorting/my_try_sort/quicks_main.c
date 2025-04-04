#include <stdio.h>
#include "quicksort.h"
#define	MAXLEN	10000

int main(void) {
	char hello_msg[] = "Enter array size N:\n";
	char hello_msg2[] = "Enter number of arrays to sort:\n";
	char result_msg[] = "Sorted array:\n";
	int n;
	double arr[MAXLEN];

	printf("%s", hello_msg);
	scanf("%d", &n);

	printf("%s", hello_msg2);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &arr[i]);

	quicksort(arr, 0, n-1);

	printf("%s", result_msg);
	for (int i = 0; i < n; ++i)
		printf("%lf ", arr[i]);
	printf("\n");

}
