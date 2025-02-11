#include <stdio.h>
#include <stdlib.h>	/* for atof() */

#include "stack.h"
#include "getop.h"

#define MAXOP	100	/* max size of operand or operator */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void) {
	int type, n1, n2;
	double op1, op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF ) {
		switch(type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0)
				push(pop() / op2);
			else
				printf("Error: division by zero!\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case '%':
			op2 = pop();
			n2 = (int)op2;
			printf("n2 = %d\n", n2);
			if (n2 - op2 != 0) {
				printf("Number %g is not integer\n", op2);	
				break;
			}
			
			op1 = pop();
			n1 = (int)op1;
			printf("n1 = %d\n", n1);
			if (n1 - op1 != 0) {
				printf("Number %g is not integer\n", op1);
				break;
			}
			push(n1 % n2);
			break;
		default:
			printf("Error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}


