

#include <stdio.h>

#define MAXLEN	1000

#define F_IN	"test_program.c"
#define F_OUT	"test_program_out.c"

#define TRUE	1
#define FALSE	0



void removecomments(char *filename_in, char *filename_out);


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
		
		;		
		
		
		i = 0; j = 0;

		while ( s[i] != '\0') {


			if (s[i] = '"' && !(quote_str) ) {
				if ( !(dquote_str) ) {
					dquote_str = TRUE; 
					++i;
				}

				else {
					dquote_str = FALSE; 
					++i;
				}
				
			}

			else if (s[i] = '\'' && !(dquote_str) ) {
				if ( !(quote_str) ) {
					quote_str = TRUE; 
					++i;
				}
				
				else {
					quote_str = FALSE; 
					++i;
				}
			}

			else if ( !(quote_str || dquote_str) ) {


				
	
				if (s[i] == '/' && s[i+1] == '/' && !(sl_comm || ml_comm) ) {
					
					sl_comm = TRUE;
					i = i + 2;
				}
	
				else if (s[i] == '/' && s[i+1] == '*' && !(sl_comm || ml_comm) ) {
					
					ml_comm = TRUE;
					i = i + 2;
				}
	
				else if (s[i] == '\n' && sl_comm) {
					
					sl_comm = FALSE;
				}
	
				else if (s[i] == '*' && s[i+1] == '/' && ml_comm) {
					
					ml_comm = FALSE;
					i = i + 2;
				}
	
				else if ( !(sl_comm || ml_comm) ) {
					
					out_s[j] = s[i];
					++j;
					++i;
	
				}
				else {
					++i;
				}

			}
	
		}
			
		out_s[j] = '\0';  ++j;

		printf("%s", out_s);
		fprintf(f_out, "%s", out_s);
	}

	fclose(f_in); 
	fclose(f_out); 

}
