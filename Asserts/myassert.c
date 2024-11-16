#include <stdio.h>
#include <assert.h>
#include <string.h>

int test1(int x);

int test2(int x);

void main(void) {
	
	char hello_msg[] = "Solve a problem: ";
	char task1_msg[] = "5 + 2 = ";
	char task2_msg[] = "3 * 7 = ";
	
	int x;

	// Running tests
	printf("%s\n", hello_msg);
	printf("%s", task1_msg);
	scanf("%d", &x);
	assert(test1(x));

	printf("%s\n", hello_msg);
	printf("%s", task2_msg);
	scanf("%d", &x);
	assert(test2(x));
}

int test1(int x) {
	return 5 + 2 == x;
}

int test2(int x) {
	return 3 * 7 == x;
}
