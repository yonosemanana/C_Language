#include <stdio.h>
#include <ctype.h>

/* atoi: convert s to integer; version 2 */
int atoi (char s[]) {
	int i, n, sign;

	for(i = 0; isspace(s[i]); ++i) /* skip whitespaces */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') /* skip sign */
		++i;
	for(n = 0; isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');

	return sign * n;
}

int main(void) {
	char *s1 = "   -257";
	char *s2 = "+34";
	char *s3 = "  100a";

	printf("s1 = %s, atoi(s1) = %d\n", s1, atoi(s1));
	printf("s2 = %s, atoi(s2) = %d\n", s2, atoi(s2));
	printf("s3 = %s, atoi(s3) = %d\n", s3, atoi(s3));

	return 0;
}
