#include <stdio.h>

#define __sort_func_arg		void (*sort_func)(int v[], int n)

void test_array(int v[], int n, __sort_func_arg);

void test_sorting(__sort_func_arg) {
	int n;
	int v1[] = {1, 10, 2, -5, 100, 4};
	int v2[] = {3};
	int v3[] = {1, 3, 100};
	int v4[] = {1000, 200, 500, -100, 1, -1, 3, 0, -3};
	int v5[] = {1, -1, 0, 1, 1, -1, 0, 1, 1, -1, 0, 2, 1, 0, 1, -1, 0, 100, 1, -100, 1, -10, 10, 1, 0, 1, -1, 100, -1, 100, 10, 1, 0, -1, 0, -2, -10, 1, 10, 100, -1, 100, 1, 100, 10, -1, 0, 1, 1, 0, 1, -1, 2, 5, 0, -5, 100, -5, 5, 1, 50, 100, -50, 10, -1, -5, 5, 10, 50, 100};
	int v6[] = {1, -1, 0, 1, 1, -1, 0, 1, 1, -1, 0, 2, 1, 0, 1, -1, 0, 100, 1, -100, 1, -10, 10, 1, 0, 1, -1, 100, -1, 100, 10, 1, 0, -1, 0, -2, -10, 1, 10, 100, -1, 100, 1, 100, 10, -1, 0, 1, 1, 0, 1, -1, 2, 5, 0, -5, 100, -5, 5, 1, 50, 100, -50, 10, -1, -5, 5, 10, 50, 100, 1, -1, 0, 1, 1, -1, 0, 1, 1, -1, 0, 2, 1, 0, 1, -1, 0, 100, 1, -100, 1, -10, 10, 1, 0, 1, -1, 100, -1, 100, 10, 1, 0, -1, 0, -2, -10, 1, 10, 100, -1, 100, 1, 100, 10, -1, 0, 1, 1, 0, 1, -1, 2, 5, 0, -5, 100, -5, 5, 1, 50, 100, -50, 10, -1, -5, 5, 10, 50, 100, 1, -1, 0, 1, 1, -1, 0, 1, 1, -1, 0, 2, 1, 0, 1, -1, 0, 100, 1, -100, 1, -10, 10, 1, 0, 1, -1, 100, -1, 100, 10, 1, 0, -1, 0, -2, -10, 1, 10, 100, -1, 100, 1, 100, 10, -1, 0, 1, 1, 0, 1, -1, 2, 5, 0, -5, 100, -5, 5, 1, 50, 100, -50, 10, -1, -5, 5, 10, 50, 100};
	int v7[] = {5, 2, 3, 1};

	n = sizeof(v1) / sizeof(int);
	test_array(v1, n, sort_func);

	n = sizeof(v2) / sizeof(int);
	test_array(v2, n, sort_func);

	n = sizeof(v3) / sizeof(int);
	test_array(v3, n, sort_func);

	n = sizeof(v4) / sizeof(int);
	test_array(v4, n, sort_func);

	n = sizeof(v5) / sizeof(int);
	test_array(v5, n, sort_func);
	
	n = sizeof(v6) / sizeof(int);
	test_array(v6, n, sort_func);
	
	n = sizeof(v7) / sizeof(int);
	test_array(v7, n, sort_func);
}




/* Run tests and print input and output data */
void test_array(int v[], int n, __sort_func_arg) {

	for (int i = 0; i < n-1; ++i)
		printf("%d, ", v[i]);
	printf("%d\n", v[n-1]);
	
	sort_func(v, n);
	
	for (int i = 0; i < n-1; ++i)
		printf("%d, ", v[i]);
	printf("%d\n", v[n-1]);

}


