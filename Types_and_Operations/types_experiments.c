#include <stdio.h>
#include <string.h>

enum months {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

#define num_months	12

int mystrlen(const char s[]);

void main(void) {
	enum months m = Aug;
	
	const int n = 10;

	const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	const char mystr[] = "Hello, world!";
	char msg[] = "String: ";

	printf("%d\n", m);
	
	m = 15;
	printf("%d\n", m);
	
	printf("%d\n", n);
	//n = 11;
	//++n;
	printf("%d\n", n);

	for (int i = 0; i < sizeof(alphabet) / sizeof(alphabet[0]); ++i) {
		printf("%c - %d\n", alphabet[i], alphabet[i]);
	}

	strcat(msg, mystr);
	strcat(msg, "\n");
	printf("%s", msg);
	printf("Length of string: %ld\n", strlen(mystr));
	printf("Length of string (calcualted by my function): %d\n", mystrlen(mystr));
}

int mystrlen(const char s[]) {
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}
