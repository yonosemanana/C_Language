#include <stdio.h>

#define MAXLEN	1000

#define F_IN	"f_in.txt"
#define F_OUT	"f_out.txt"

void removecomments(void);
/* The function reads C program from input and deletes all comments from it */



int main(void) {

	char s[MAXLEN];

	FILE *f_in, *f_out;

	FILE* another_file;

	f_in = fopen(F_IN, "r");
	f_out = fopen(F_OUT, "w");

	while( fgets(s, MAXLEN, f_in) ) {
		printf("%s", s);
		fprintf(f_out, "%s", s);
	}

	fclose(f_in);
	fclose(f_out);

}
