#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n);

int binsearch2(int x, int v[], int n);

int print_int_array(int v[], int n);

void main() {
	int x = 10;
	int n = 10;
	int v1[] = {-5, -1, 0, 3, 4, 7, 10, 14, 20, 100};
	int v2[] = {-100, -90, 10, 20, 30, 50, 100, 110, 120, 1000};
	int v3[] = {0, 9, 50, 90, 100, 110, 1000, 3000, 7000, 10000};
	int index;

	print_int_array(v1, n);
	index = binsearch2(x, v1, n);
	printf("index of %d = %d\n", x, index);

	print_int_array(v2, n);
	index = binsearch(x, v2, n);
	printf("index of %d = %d\n", x, index);
	
	print_int_array(v3, n);
	index = binsearch2(x, v3, n);
	printf("index of %d = %d\n", x, index);
}

int binsearch(int x, int v[], int n) {
	int low, high, mid;
	
	low = 0;
	high = n-1;
	while (low <= high) {
		mid = (low + high) / 2;
		printf("high = %d, low = %d, mid = %d, v[mid] = %d\n", high, low, mid, v[mid]);
		if (x < v[mid])
			high = mid-1;
		else if (x > v[mid])
			low = mid+1;
		else
			return mid; /* found match */
	}
	return -1; /* no match */

}

/* Another version of binary search */
int binsearch2(int x, int v[], int n) {
	int low, high, mid;
	
	low = 0;
	high = n-1;
	while (low < high) {
		mid = (low + high) / 2;
		printf("high = %d, low = %d, mid = %d, v[mid] = %d\n", high, low, mid, v[mid]);
		if (x > v[mid])
			low = mid+1;
		else
			high = mid;
	}	
	if (x == v[low])
		return low; /* found match */
	else
		return -1; /* no match */
}


int print_int_array(int v[], int n) {	
	printf("n = %d\n", n);
	for (int i = 0; i < n-1; ++i)
		printf("%d, ", v[i]);
	printf("%d\n", v[n-1]);
}
