// This is the first test comment!

#include <stdio.h>

#define MAXLEN	1000

#define F_IN	"test_program.c"
#define F_OUT	"test_program_out.c"

#define TRUE	1
#define FALSE	0



void removecomments(void);
/* The function reads C program from input and deletes all comments from it */



int main(void) {

	char s[MAXLEN], out_s[MAXLEN];
	FILE *f_in, *f_out;
	int i, j, sl_comm, ml_comm;

	f_in = fopen(F_IN, "r");
	f_out = fopen(F_OUT, "w");



	sl_comm = FALSE; ml_comm = FALSE;
	
	while ( fgets(s, MAXLEN, f_in)) {
		// Read line of text from f_in file.
		;		
		/* If you find start of comments pattern, attention!
		 * // - single line comment, then skip everything till end of line ("\n") 
		 * / * - multiline comment, then skip everything till * / (without spaces)
		 */
		
		i = 0; j = 0;

		while ( s[i] != '\0') {

			// printf("%c", s[i]);

			if (s[i] == '/' && s[i+1] == '/' && !(sl_comm || ml_comm) ) {
				// Start of single-line comment
				sl_comm = TRUE;
				i = i + 2;
			}

			else if (s[i] == '/' && s[i+1] == '*' && !(sl_comm || ml_comm) ) {
				// Start of multi-line comment
				ml_comm = TRUE;
				i = i + 2;
			}

			else if (s[i] == '\n' && sl_comm) {
				// End of single-line comment
				sl_comm = FALSE;
			}

			else if (s[i] == '*' && s[i+1] == '/' && ml_comm) {
				// End of multi-line comment
				ml_comm = FALSE;
				i = i + 2;
			}

			else if ( !(sl_comm || ml_comm) ) {
				// Normal text of C program. Then write it to output string
				out_s[j] = s[i];
				++j;
				++i;

			}
			else {
				++i;
			}
		}

		// Adding \0 to the end of output string
		out_s[j] = '\0'; /* This is test 
				    multi-line comment */ ++j;

		printf("%s", out_s);
		fprintf(f_out, "%s", out_s);
	}

	fclose(f_in); // This is test // comment
	fclose(f_out); //// This is another test comment

}
