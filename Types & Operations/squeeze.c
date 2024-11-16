#include <stdio.h>

enum boolean {FALSE = 0, TRUE = 1};

char *squeeze (char s1[], char s2[]);

void main (void) {
	char s1[] = "Hello, world!";
	char s2[] = "My name is Alex!";

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("squeeze(s1, s2): %s\n", squeeze(s1, s2));

}

char *squeeze (char s1[], char s2[]) {
/* This function deletes characters from s1 which
 * exist in s2. String s1 is updated "in place" */
	int i, j;
	enum boolean in_s2;

	i = 0;
	j = 0;
	for (; s1[i] != '\0'; ++i) {
		in_s2 = FALSE;
		for (int k = 0; s2[k] != '\0' && !in_s2; ++k) {
			if (s1[i] == s2[k]) {
				in_s2 = TRUE;
				break;
			}
		}
		if (!in_s2) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';

	return s1;

}
