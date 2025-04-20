#include <stdio.h>
#include "myfuncs.h"

int main(void) {
	
	char c;
	char *msg = "Hello";
	int msg_len = sizeof(msg) / sizeof(char);

	while (c = getch() != EOF)
		putchar(c);

	for (int i = msg_len-1; i >= 0; i--)
		ungetch(msg[i]);
	
	for (int i = 0; i < msg_len; i++) 
		putchar(getch());
	printf("\n");
}
