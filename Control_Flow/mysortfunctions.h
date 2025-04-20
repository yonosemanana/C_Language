
#define __sort_func_arg		void (*sort_func)(int v[], int n)

void test_array(int v[], int n, __sort_func_arg);

void test_sorting(__sort_func_arg);


