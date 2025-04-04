#include <stdio.h>

void quicksort(double arr[], int left, int right) {
	int mid;
	double tmp;

	mid = (left + right) / 2;
	/* printf("Start iteration: left = %d, right = %d, mid = %d\n", left, right, mid);
	for (int i = left; i <= right; ++i)
		printf("%lf ", arr[i]);
	printf("\n");*/

	if (left < mid) {
		// printf("left = %d < mid = %d\n", left, mid);
		quicksort(arr, left, mid);
	}
	if (mid+1 < right) {
		// printf("mid+1 = %d < right = %d\n", mid+1, right);
		quicksort(arr, mid+1, right);
	}
	while (right > left && arr[mid] > arr[mid+1]) {
		// printf("mid = %d, arr[mid] = %lf > arr[mid+1] = %lf\n", mid, arr[mid], arr[mid+1]);
		tmp = arr[mid];
		arr[mid] = arr[mid+1];
		arr[mid+1] = tmp;
		if (right - left > 1) {
			// printf("right = %d - left = %d > 1\n", right, left);
			quicksort(arr, left, mid);
			quicksort(arr, mid+1, right);
		}
	}
	/* printf("End iteration: left = %d, right = %d, mid = %d\n", left, right, mid);
	for (int i = left; i <= right; ++i)
		printf("%lf ", arr[i]);
	printf("\n\n");	*/
}


void quicksort_old(double arr[], int left, int right) {
	int mid;
	double tmp;

	mid = (left + right) / 2;

	if (mid > left + 1) 
		quicksort_old(arr, left, mid);
	if (mid == left + 1)
		if (arr[left] > arr[mid]) {
			tmp = arr[left];
			arr[left] = arr[mid];
			arr[mid] = tmp; 
		}
	if (right > mid + 2)
		quicksort_old(arr, mid + 1, right);
	if (right == mid + 2)
		if (arr[mid+1] > arr[right]) {
			tmp = arr[mid+1];
			arr[mid+1] = arr[right];
			arr[right] = tmp;
		}
	
	
	/* for (int i = left; i < right; ++i)
		printf("%lf ", arr[i]);
	printf("\n");	*/

}
