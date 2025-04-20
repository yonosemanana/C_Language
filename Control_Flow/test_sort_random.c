#include <stdio.h>
#include "myrandint.h"
#include "mysort.h"
#include "myshellsort.h"
#include "mysortfunctions.h"

#define F_IN	"rand_int_array.txt"
#define F_OUT	"sorted_array.txt"

#define N	1000

void main(void) {
	
	int arr[N];
	int i, n;
	FILE *f_in, *f_out;

	f_in = fopen(F_IN, "r");
	f_out = fopen(F_OUT, "w");
	
	for (i = 0; fscanf(f_in, "%d", &arr[i]) == 1; ++i)
		;
	n = i;
	// printf("n = %d\n", n);
	
	myshellsort(arr, n);
	//mysort2(arr, n);

	for (int i = 0; i < n; ++i)
		fprintf(f_out, "%d ", arr[i]); 

	fclose(f_in);
	fclose(f_out);

}
