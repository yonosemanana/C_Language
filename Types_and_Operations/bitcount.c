#include <stdio.h>
#include "printbinary.h"

int bitcount(unsigned x);

int bitcount2(unsigned x);

void main(void) {
	unsigned int x;

	x = 0xa2b3;
	printf("0x%04x\n", x);
	pbin(x);
	printf("\n");
	printf("bitcount(0x%04x) = %d\n", x, bitcount(x));
	printf("bitcount2(0x%04x) = %d\n", x, bitcount2(x));
	
	x = 0x70F9;
	printf("0x%04x\n", x);
	pbin(x);
	printf("\n");
	printf("bitcount(0x%04x) = %d\n", x, bitcount(x));
	printf("bitcount2(0x%04x) = %d\n", x, bitcount2(x));
	
}

int bitcount(unsigned x) {
	int b;
	for (b = 0; x != 0; x = x >> 1) {
		//printf("0x%x\n", x);
		if ((x & 0x1) == 1)	
			++b;
	}
	return b;

}

int bitcount2(unsigned x) {
	int b;
	for (b = 0; x != 0; x =	x & (x-1))
		++b;
	
	return b;
}


