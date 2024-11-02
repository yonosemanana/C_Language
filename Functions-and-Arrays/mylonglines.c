#include <stdio.h>

#define LINELEN	10
#define MAXLEN	1000


int splitline(char line[MAXLEN], char newline[MAXLEN], int len, int linelen);

int main (void) {
	char c;
	char line[MAXLEN], newline[MAXLEN];
	int len = 0, newlen = 0;
	int i = 0;

	c = getchar();
	while (c != EOF) {

		i = 0;
		while (c != '\n') {
			line[i] = c;
			++i;
			c = getchar();	
		}
		line[i] = '\n';
		len = i;
		
		/* Printing line which was read, just for test purposes
		for (int j = 0; j <= len; ++j)
			putchar(line[j]);
		*/
		
		newlen = splitline(line, newline, len, LINELEN);
		// printf("newlen = %d\n", newlen);
		for(i = 0; i < newlen; ++i)
		       putchar(newline[i]);	

		c = getchar();
	}

	return 0;
}

int splitline(char line[MAXLEN], char newline[MAXLEN], int len, int linelen) {
	/* This function divides line to chunks with no more then linelen characters in each one.
	 * The line is divided to chunks so, that last characters in each chunk are spaces or tabs.
	 * "/n" is added between chunks. The result is written to char newline[] */

	int i, j, k, l;
	

	i = 0; // Index of line[] characters
	j = 0; // Index of newline[] characters

	while (i < len) {
		/* In general, we copy a part of line[i] -> newline[j] and add "\n" where 
		 * necessary, i.e. at line width (by default LINELEN = 80)
		 */
	
		if (i + linelen >= len) {
			// copy line[i:len] -> newline and exit loop
			for (l = i; l < len; ++l) {
				newline[j] = line[l];
				++j;
			}
			i = len;
		}	
		else {
			for (k = i + linelen - 1; k > i && (line[k] != ' ' && line[k] != '\t'); --k)
				// printf("k = %d - %c\n", k, line[k]);
				;
			if (k == i) {
				// Line is too long and all LINELEN characters are not spaces. 
				// Split it at LINELEN anyway.
				for (l = i; l < i + linelen; ++l) {
					newline[j] = line[l];
					++j;
				}
				i += linelen;
			}
			else {
				// Part of line[i:k] write to newlen
				for (l = i; l < k; ++l) {
					newline[j] = line[l];
					++j;					
				}
				i = k;
			}
			

		}	
		newline[j] = '\n';
		++j;
      
	}

	return j;
}
