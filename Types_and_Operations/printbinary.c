#include <stdio.h>
#include <limits.h>

#define UINT_BITS	sizeof(unsigned) * CHAR_BIT

void pbin(unsigned x) {
/* Prints binary representation of unsigned x */
	char t;
	for (int i = UINT_BITS-1; i >= 0; --i) {
		t = (x >> i) & 0x1;
		switch (t) {
			case 1:
				printf("1");
				break;
			case 0:
				printf("0");
				break;
		}
		if (i % CHAR_BIT == 0)
			printf(" ");
				
	}
}

