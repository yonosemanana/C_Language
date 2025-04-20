#include <stdio.h>
#include "myfuncs.h"

int main (void) {
	int status_code, num;
	
	printf("Start reading integers...\n");
	status_code = getint(&num);
	while(status_code > 0) {
		printf("%d\n", num);
		status_code = getint(&num);
	}
	printf("Stop reading integers...\n");

	return 0;
}
