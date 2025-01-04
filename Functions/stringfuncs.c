#include <stdio.h>

/* getline: get line into s, return length */
int mygetline(char s[], int lim) {
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, k;

	for (i = 0; s[i] != '\0'; ++i) {
		for (k = 0; s[i+k] != '\0' && t[k] != '\0' && s[i+k] == t[k]; k++)
			;
		if (t[k] == '\0' && k > 0)
			return i;
	}
	return -1;
}
