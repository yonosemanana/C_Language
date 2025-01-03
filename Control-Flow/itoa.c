#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXLEN	1000

void itoa(int n, char s[]);

void myreverse(char s[]);

void main (void) {
	int n1 = -123;
	int n2 = 2403;
	int n3 = INT_MIN;
	int n4 = INT_MAX;
	int n5 = 0;

	char s[MAXLEN];
	char s1[] = "Hello, world!";

	printf("s1 = %s\n", s1);
	myreverse(s1);
	printf("reverse s1 = %s\n", s1);
		
	itoa(n1, s);
	printf("n1 = %d, str(n1) = %s\n", n1, s);
	
	itoa(n2, s);
	printf("n2 = %d, str(n2) = %s\n", n2, s);

	itoa(n3, s);
	printf("n3 = %d, str(n3) = %s\n", n3, s);

	itoa(n4, s);
	printf("n4 = %d, str(n4) = %s\n", n4, s);

	itoa(n5, s);
	printf("n5 = %d, str(n5) = %s\n", n5, s);
	
}

/* itoa: convert n to characters in s */
void itoa (int n, char s[]) {
	int i, sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;

	i = 0;
	do {
		s[i++] = (n % 10) * sign + '0';
		n /= 10;
	} while (n * sign > 0);
	if (sign < 0)
		s[i++] = '-';
	//printf("i = %d\n", i);
	s[i] = '\0';
	
	myreverse(s);
	//printf("%s\n", s);
}

void myreverse (char s[]) {
	char tmp;
	int l;

	l = strlen(s);
	for (int i = 0; i < l/2; ++i) {
		tmp = s[l-1-i];
		s[l-1-i] = s[i];
		s[i] = tmp;
	}
}
