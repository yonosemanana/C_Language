#include <stdio.h>
#include "../atof.h"

int main (void) {

	double d;
	char s1[] = "    -100.37";
	char s2[] = "201.5e-2";
	char s3[] = "  -237.73001E+13";

	d = myatof(s1);
	printf("%.2f\n", d);
	
	d = myatof(s2);
	printf("%f\n", d);

	d = myatof(s3);
	printf("%f\n", d);
	
	return 0;
}
