

#include <stdio.h>

#define MAXLEN	1000

#define F_IN	"test_program.c"
#define F_OUT	"test_program_out.c"

#define TRUE	1
#define FALSE	0



void removecomments(void);




int main(void) {

	char s[MAXLEN], out_s[MAXLEN];
	FILE *f_in, *f_out;
	int i, j, sl_comm, ml_comm;

	f_in = fopen(F_IN, "r");
	f_out = fopen(F_OUT, "w");



	sl_comm = FALSE; ml_comm = FALSE;
	
	while ( fgets(s, MAXLEN, f_in)) {
		
		;		
		
		
		i = 0; j = 0;

		while ( s[i] != '\0') {

			

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

		
		out_s[j] = '\0';  ++j;

		printf("%s", out_s);
		fprintf(f_out, "%s", out_s);
	}

	fclose(f_in); 
	fclose(f_out); 

}
