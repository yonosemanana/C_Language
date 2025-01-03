#include <stdio.h>
#include <ctype.h>

#define MAXLEN	1000

void expand(char s1[], char s2[]);

void main (void) {
	char s1[] = "Hello, world! a-z";
	char s2[] = "-1-9a-z";
	char s3[] = "a-B-C-t3-7-";
	char s4[] = "1239-0 z-a00-5";
	char s[MAXLEN];

	printf("%s\n", s1);
	expand(s1, s);
	printf("%s\n", s);
	
	printf("%s\n", s2);
	expand(s2, s);
	printf("%s\n", s);

	printf("%s\n", s3);
	expand(s3, s);
	printf("%s\n", s);
	
	printf("%s\n", s4);
	expand(s4, s);
	printf("%s\n", s);

}

/* Expands shorthand notations like a-z in the string s1 into
 * the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits. */
void expand(char s1[], char s2[]) {
	int i, j, k;

	i = 0; j = 0;
	while (s1[i] != '\0'|| s1[i+1] != '\0' || s1[i+2] != '\0') {
		if (isdigit(s1[i]) && s1[i+1] == '-' && isdigit(s1[i+2]) && (s1[i] < s1[i+2])) {
			for (k = 0; k < s1[i+2] - s1[i]; ++k) 
				s2[j+k] = s1[i] + k;
			i += 2;
			j += k;
		}
		else if (isalpha(s1[i]) && s1[i+1] == '-' && isalpha(s1[i+2]) 
				&& (tolower(s1[i]) < tolower(s1[i+2]))) {
			for (k = 0; k < tolower(s1[i+2]) - tolower(s1[i]); ++k)
				s2[j+k] = tolower(s1[i]) + k;
			i += 2;
			j += k;

		}
		else {
			s2[j] = s1[i];
			++i; 
			++j;
		}
	}
	s2[j] = '\0';
}
