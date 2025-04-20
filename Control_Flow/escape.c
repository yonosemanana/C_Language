#include <stdio.h>

#define MAXLEN	1000

int escape(char s[], char t[]);
int escape_reverse(char s[], char t[]);

int main(void) {
	char t[] = "a b c	d123\n"
		    "x\n"
		    "y";
	char s[MAXLEN];
	char q[MAXLEN];

	printf("t = %s\n", t);
	escape(s, t);
	printf("s = %s\n", s);

	escape_reverse(q, s);
	printf("q = %s\n", q);
}

/* The function converts characters like newline and tab into
 * visible escape sequences like \n and \t as it copies string t to s */
int escape(char s[], char t[]) {
	int i = 0;
	int j = 0;

	while(t[i] != '\0') {
		switch(t[i]) {
			case '\t':
				s[j] = '\\'; 
				s[j+1] = 't'; 
				j = j+2;
				++i;
				break;
			case '\n':
				s[j] = '\\'; 
				s[j+1] = 'n';
			        j = j+2;
				++i;
				break;
			default:
				s[j] = t[i];
				++j;
				++i;
				break;

		}
	}
	s[j] = '\0';
	return j;
}

/* The function converts visible escape sequences like \n and \t 
 * to characters like newline and tab as it copies string t to s */
int escape_reverse(char s[], char t[]) {
	int i = 0;
	int j = 0;

	while(t[i] != '\0') {
		switch(t[i]) {
			case '\\':
				switch(t[i+1]) {
					case 'n':
						s[j] = '\n'; 
						i = i+2;
						++j;
						break;
					case 't':
						s[j] = '\t'; 
			        		i = i+2;
						++j;
						break;
				}
				break;
			default:
				s[j] = t[i];
				++j;
				++i;
				break;

		}
	}
	s[j] = '\0';
	return j;
}
