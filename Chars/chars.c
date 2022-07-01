/*
 * chars.c
 *
 *  Created on: Apr 22, 2022
 *      Author: alper
 */

#include <stdio.h>

main()
{
	int c;

	c = getchar();
	while (c != EOF) {
		//printf("\t%d\n", c != EOF);
		putchar(c);
		c = getchar();
	}
	//printf(EOF);
}
