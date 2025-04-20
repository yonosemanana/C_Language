#include <stdio.h>
#include "myfuncs.h"

int main (void) {
	int status_code;
	double f;
	
	printf("Start reading floats...\n");
	status_code = getfloat(&f);
	while (status_code > 0) {
		printf("%lf\n", f);
		status_code = getfloat(&f);
	}
	printf("Stop reading floats...\n");

	return 0;
}
