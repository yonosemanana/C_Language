#include <stdio.h>


float sum(float arr[], int len) {

	float s = 0;

	for (int i = 0; i < len; ++i) {
		s += arr[i];
		// printf("Temp sum: %f\n", s);
	}
	return s;

}

int main () {

	float test_array[] = {1.0, 2, 3, 5.0, 10, -1};
	int len;

	printf("Array:\n");
	len = sizeof(test_array) / sizeof(test_array[0]);
	printf("sizeof test_array[0]: %d\n");

	for (int i = 0; i < len; ++i) {
		printf("%.2f\n", test_array[i]);
	}
	printf("\nSum:\n");
	printf("%.2f", sum(test_array, len));
		
	return 0;
}
