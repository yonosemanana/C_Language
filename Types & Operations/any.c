#include <stdio.h>

enum boolean {FALSE = 0, TRUE = 1};

int any (char s1[], char s2[]);

void main (void) {
	char s1[] = "Hello, world!";
	char s2[] = "My name is Alex!";
	char s3[] = "abc";

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("any(s1, s2): %d\n", any(s1, s2));
	printf("s3: %s\n", s3);
	printf("any(s1, s3): %d\n", any(s1, s3));
	printf("any(s2, s3): %d\n", any(s2, s3));

}

int any (char s1[], char s2[]) {
/* This function returns first index in s1 where 
 * is any character from s2. If there is no such character,
 * returns -1. */

	for (int i = 0; s1[i] != '\0'; ++i) 
		for (int k = 0; s2[k] != '\0'; ++k) 
			if (s1[i] == s2[k]) 
				return i;
	return -1;

}
