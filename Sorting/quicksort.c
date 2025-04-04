#include <stdio.h>

/* swap two double numbers with indexes x, y in array */
void swap (double arr[], int x, int y) {
	double tmp;
	tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}

/* Quick sort algorithm (my version, ha-ha!) */
void quicksort(double arr[], int left, int right) {

	/* Divide array on two parts, where any element from the left part
	 * is less than any element from the right part. */
	int sep_index;
	double sep_value;
	sep_index = (left + right) / 2; // sep_index can be arbitrary
	sep_value = arr[sep_index];

	/* Moving sep_value to the leftmost element of array to start sorting
	 *  array into two part, when (left) < (right) */
	swap(arr, left, sep_index);
	sep_index = left;
	
	for (int i = left + 1; i <= right; i++) {
		if (arr[i] < sep_value) {
			swap(arr, i, sep_index + 1);
			swap(arr, sep_index, sep_index + 1);
			sep_index = sep_index + 1;
		}
	}
	printf("sep_index = %d\n", sep_index);
	for (int i = left; i <= right; i++)
		printf("%lf ", arr[i]);
	printf("\n\n");

	if (left < sep_index)
		quicksort(arr, left, sep_index);
	if (sep_index + 1 < right)
		quicksort(arr, sep_index + 1, right);

}


