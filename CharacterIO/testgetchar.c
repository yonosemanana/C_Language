#include <stdio.h>

void main() {
	
	char c;
	int test;
	
	while (1) {
		c = getchar();
		test = (c != EOF);
		printf("%d\n", test);
		if (!test) {
			break;
		}
	}

}
