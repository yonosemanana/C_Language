#include <stdio.h>
#define MAXVAL	100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f) {
	if (sp < MAXVAL) 
		val[sp++] = f;
	else
		printf("Error: stack is full, can't push %g\n", f);
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack is empty\n");
		return 0.0;
	}
}
