#include <stdio.h>
#include <stdlib.h>

/* Swap values of two integers using pointers */
void swap(int *, int *);

int main (void) {
	int x, y;

	printf("Enter two integer numbers: \n");
	scanf("%d %d", &x, &y);
	printf("x = %d, y = %d\n", x, y);

	swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);
	
	return 0;
}

void swap(int *px, int *py) {
	int *tmp;
	tmp = (int *)malloc(sizeof(int));

	*tmp = *px;
	*px = *py;
	*py = *tmp;
}
