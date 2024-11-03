// This is the first test comment!

#include <stdio.h>

#define MAXLEN	1000

#define F_IN	"test_program.c"
#define F_OUT	"test_program_out.c"

#define TRUE	1
#define FALSE	0



void removecomments(char *filename_in, char *filename_out);
/* The function reads C program from input file and deletes all comments
 * and writes the program without comments to output file */

int main(void) {
	removecomments(F_IN, F_OUT);
}

void removecomments(char *filename_in, char *filename_out) {

	char s[MAXLEN], out_s[MAXLEN];
	int i, j, sl_comm, ml_comm, quote_str, dquote_str;
	FILE *f_in, *f_out;
	f_in = fopen(filename_in, "r");
	f_out = fopen(filename_out, "w");

	char test_str[MAXLEN] = "/* This is comment hidden inside string! */";
	char test_str2[MAXLEN] = "/* This is another comment \
				  in multiline string! */";
	char test_str3[MAXLEN] = "// This time it's single-line comment in string! ";

	sl_comm = FALSE; ml_comm = FALSE;
	quote_str, dquote_str = FALSE;
	
	while ( fgets(s, MAXLEN, f_in)) {
		// Read line of text from f_in file.
		;		
		/* If you find start of comments pattern, attention!
		 * // - single line comment, then skip everything till end of line ("\n") 
		 * / * - multiline comment, then skip everything till * / (without spaces)
		 */
		
		i = 0; j = 0;

		while ( s[i] != '\0') {


			if (s[i] = '"' && !(quote_str) ) {
				if ( !(dquote_str) ) {
					dquote_str = TRUE; // Opening \" of string
					++i;
				}

				else {
					dquote_str = FALSE; // Closing \" of string
					++i;
				}
				
			}

			else if (s[i] = '\'' && !(dquote_str) ) {
				if ( !(quote_str) ) {
					quote_str = TRUE; // Opening \' of string
					++i;
				}
				
				else {
					quote_str = FALSE; // Closing \' of string
					++i;
				}
			}

			else if ( !(quote_str || dquote_str) ) {


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
