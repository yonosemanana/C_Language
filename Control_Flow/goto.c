#include <stdio.h>

void main (void) {
	
	int i;
	int n = 100;
	
	i = 0;

	even:
		printf("%d is even\n", i);
		goto continue_loop;

	
	odd:
		printf("%d is odd\n", i);
		goto continue_loop;

	while (i < n) {
		if (i % 2 == 0)
			goto even;
		else
			goto odd;

		continue_loop:
			++i;
	}
		

}
