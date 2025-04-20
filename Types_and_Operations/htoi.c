#include <stdio.h>

#define NUM_TESTS	8	

int htoi (char s[]);

void main (void) {
	char s1[] = "";
	char s2[] = "Hello, world!";
	char s3[] = "0xa$";	
	char s4[] = "0XaB";
	char s5[] = "10FE";
	char s6[] = "15";
	char s7[] = "0x";
	char s8[] = "X";

	char *s[NUM_TESTS] = {s1, s2, s3, s4, s5, s6, s7, s8};

	for (int i = 0; i < NUM_TESTS; ++i) {
		printf("Hex string: %s\n", s[i]);
		printf("Decimal number: %d\n\n", htoi(s[i]));
	}
}

int htoi (char s[]) {
	int i = 0;
	int n = 0;
	
		
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) 
		i = i + 2;

	while (s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9') {
			n = 16 * n + s[i] - '0';
			++i;
		}
		else if (s[i] >= 'A' && s[i] <= 'F') {
			n = 16 * n + s[i] - 'A' + 10;
			++i;
		}
		else if (s[i] >= 'a' && s[i] <= 'f') {
			n = 16 * n + s[i] - 'a' + 10;
			++i;
		}
		else {
			return -1;
		}
	}
	return n;
}
