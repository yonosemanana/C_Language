#include <stdio.h>
#include "mystr.h"

void itob(int n, char s[], int b);

void main (void) {
	int n;
	int b;
	char* s;

	n = -100; b = 10;
	itob(n, s, b);
	printf("n = %d, b = %d, s = %s\n", n, b, s);

	n = 256; b = 16;
	itob(n, s, b);
	printf("n = %d, b = %d, s = %s\n", n, b, s);

	n = 37; b = 4;
	itob(n, s, b);
	printf("n = %d, b = %d, s = %s\n", n, b, s);
	
	n = -160; b = 16;
	itob(n, s, b);
	printf("n = %d, b = %d, s = %s\n", n, b, s);

}


/* Converts the integer n into a base b character representation in the string s. */
void itob(int n, char s[], int b) {
	int i, sign;
	char characters[] = "0123456789abcdef";

	if (2 <= b <= 16) {

        	sign = 1;
        	if (n < 0)
                	sign = -1;

		i = 0;
		do { 
			s[i++] = characters[(n % b) * sign];
			n /= b;
		} 
		while ( n * sign > 0);

		if (sign == -1)
			s[i++] = '-';
		s[i] = '\0';
		myreverse(s);
	}
}
