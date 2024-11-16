#include <stdio.h>
#include <limits.h>

#define INT_BITS	sizeof(unsigned) * CHAR_BIT

unsigned getbits (unsigned x, int p, int n);

unsigned setbits (unsigned x, int p, int n, unsigned y);

unsigned invert(unsigned x, int p, int n);

unsigned invert2(unsigned x, int p, int n);

unsigned rightrot(unsigned x, int n);

void main(void) {
	unsigned x, y;
	int p, n;

	p = 5; n = 2;
	x = 0xa024;
	printf("getbits(0x%04x, %d, %d) = 0x%04x\n", x, p, n, getbits(x, p, n));
	p = 4; n = 3; x = 0xffeb;
	printf("getbits(0x%04x, %d, %d) = 0x%04x\n", x, p, n, getbits(x, p, n));

	p = 5, n = 4;
	x = 0xa2; y = 0xfa;
	printf("setbits(0x%04x, %d, %d, 0x%04x) = 0x%04x\n", x, p, n, y, setbits(x, p, n, y));

	p = 5, n = 2;
	x = 0xa9;
	printf("invert(0x%04x, %d, %d) = 0x%04x\n", x, p, n, invert(x, p, n));
	printf("invert2(0x%04x, %d, %d) = 0x%04x\n", x, p, n, invert2(x, p, n));
	
	x = 0xa2; n = 3;
	printf("rightrot(0x%04x, %d) = 0x%04x\n", x, n, rightrot(x, n));

}

/* getbits: get n bits from position p */
unsigned getbits (unsigned x, int p, int n) {
	return (x >> (p+1-n) & ~(~0 << n));
}

/* setbits: set rightmost n bits from y to n right bits in x starting from p */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
	unsigned t3 = (y & (~(~0 << n))) << (p+1-n);
	unsigned t2 = x & (~(~0 << (p+1-n)));
	unsigned t1 = x & (~0 << (p+1));
	
	// printf("%04x\n", ~0 >> n);
	// printf("%04x\n", (y & (~0 >> n)));
	// printf("%04x - %04x - %04x\n", t1, t2, t3);
	return (t1 | t2) | t3;

}

/* invert: inverts n bit starting from bit p of number x */
unsigned invert(unsigned x, int p, int n) {
	unsigned t1 = getbits(x, p, n);
	// unsigned t2 = t1 << (p+1-n);
	// printf("%04x\n", t1);
	// return (x & ~t1) | ~t1;
	return setbits(x, p, n, ~t1);
}

/* invert2: inverts n bit starting from bit p of number x - another version*/
unsigned invert2(unsigned x, int p, int n) {
	unsigned t1 = (x >> (p+1)) << (p+1);
	unsigned t2 = x & ~(~0 << (p+1-n));
	unsigned t3 = (~(x >> (p+1-n)) & ~(~0 << n)) << (p+1-n);
	// printf("%04x\n", t1);
	return t1 | t2 | t3;
}

/* Rotate n bits of x to the right */
unsigned rightrot(unsigned x, int n) {
	unsigned t;
	for (int i = 0; i < n; ++i) {
		t = x & 1; // Rightmost bit
		x = x >> 1;
		t = t << (INT_BITS-1);
	       	x = x | t;
	}
	return x;
}
