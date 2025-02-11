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
		
		// printf("type = %c\n", type);
		// printf("s = %s\n", s);
		
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
		case 'p':	/* print top of stack without popping */
			op1 = pop();
			push(op1);
			printf("\t%.8g\n", op1);
			break;
		case 'd':	/* duplicate top of stack */
			op1 = pop();
			push(op1);
			push(op1);
			break;
		case 's':	/* swap top two stack elements */
			op2 = pop();
			op1 = pop();
			push(op2);
			push(op1);
			break;
		case 'c':	/* clear stack */
			break;
		
		default:
			printf("Error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}


