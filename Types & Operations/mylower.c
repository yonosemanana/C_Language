#include <stdio.h>

void lower(char s[]);

void lower2(char s[]);

void main (void) {
	char s1[] = "Hello, world!";
	char s2[] = "My name is Alex!";

	printf("%s\n", s1);
	lower(s1);
	printf("%s\n", s1);

	printf("%s\n", s2);
	lower2(s2);
	printf("%s\n", s2);

}

void lower(char s[]) {
/* Convert uppercase string to lowercase, in place */
	for (int i = 0; s[i] != '\0'; ++i)
		if (s[i] >= 'A'&& s[i] <= 'Z')
			s[i] = s[i] + 'a' - 'A';
}

void lower2(char s[]) {
	for (int i = 0; s[i] != '\0'; ++i)
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 'a' - 'A' : s[i];
}
