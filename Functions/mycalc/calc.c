#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define MAXLEN	100	// Maximum depth of stack with numbers and operators in calculator


void push(double);
double pop(void);

int getop(char s[]);

int sp = 0;			// Stack pointer
double num_stack[MAXLEN];	// Stack to store numbers for RPN = Reverse Polish Notation calculator


void main (void) {
	
	int getop_rcode;
	char s[MAXLEN];
	double res, num, op1, op2;
	char *endptr;

	/* // Testing getop(s) function 
	getop_rcode = getop(s);
	//printf("%d\n", getop_rcode);

	while (getop_rcode != -1) {
		printf("%s\n", s);
		getop_rcode = getop(s);
		//printf("%d\n", getop_rcode);
	} */


	// Reading input till EOF which stops the program
	getop_rcode = getop(s);
	while (getop_rcode != -1) {

		// "\n" means pop last number from stack and print it
		if (getop_rcode == 0) {
			// printf("%d\n", getop_rcode);
			// printf("%s\n", s);

			res = pop();
			printf("%f\n", res);
		}

		errno = 0;	// Reset errno variable to 0 before usage
		// Process number or operator
		if (getop_rcode == 1) {
			// printf("%d\n", getop_rcode);
			// printf("%s\n", s);
			
			// Testing if string s contains number
			num = strtod(s, &endptr);
			if (errno == ERANGE || *endptr != '\0') {
				// printf("Not a number\n");
				// printf("%s\n", s);
				// printf("%ld\n", strlen(s));

				if (strcmp(s, "+") == 0) {
					op2 = pop();
					op1 = pop();
					res = op1 + op2;
					push(res);
				}
				else if (strcmp(s, "-") == 0) {
					op2 = pop();
					op1 = pop();
					res = op1 - op2;
					push(res);
				}
				else if (strcmp(s, "*") == 0) {
					op2 = pop();
					op1 = pop();
					res = op1 * op2;
					push(res);
				}
				else if (strcmp(s, "/") == 0) {
					op2 = pop();
					op1 = pop();
					res = op1 / op2;
					push(res);
				}
				else 
					printf("Not a supported operator!\n");
			}
			else {
				// printf("%f\n", num);
				push(num);
				
			}
		}

		getop_rcode = getop(s); // Reading next line
	}
}


/* Reading from STDIN numbers and operators till \n or EOF */
int getop(char s[]) {
	char c;
	int i = 0;

	c = getchar();
	// Omitting leading spaces;
	while (isspace(c) && c != '\n')
		c = getchar();

	while (c != EOF && c != '\n' && !(isspace(c)) ) {
		s[i] = c;
		++i;
		c = getchar();
	}
	s[i] = '\0';		// Adding end of string character to s
	
	if (c == EOF) 
		return -1;	// Return -1 means EOF reached
	else if (c == '\n' && i == 0) 
		return 0;	// Return 0 means new line in input
	else if (isspace(c)) 
		return 1;	// Return 1 means number or operator was read
}

double pop() {
	double res;
	res = num_stack[sp-1];
	--sp;
	return res;
}

void push(double num) {
	extern int sp;
	extern double num_stack[];

	num_stack[sp] = num;
	++sp;
}
