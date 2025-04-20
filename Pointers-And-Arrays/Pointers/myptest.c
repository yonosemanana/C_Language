#include <stdio.h>

int main(void) {
	
	int myvar, myvar2;
	int *pointer;
	int* pointer2;

	myvar = 10;
	myvar2 = 20;
	pointer = &myvar;
	pointer2 = &myvar2;

	printf("pointer = %p\n", pointer);
	printf("*pointer = %d\n", *pointer);
	
	printf("pointer2 = %p\n", pointer2);
	printf("*pointer2 = %d\n", *pointer2);

}
