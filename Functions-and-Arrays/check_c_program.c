#include <stdio.h>

#define MAXLEN		1000

#define INPUT_FILE	"test_program.c"

#define TRUE		1
#define FALSE		0



void check_c_syntax(char input_file[]);
/* The function reads C program from input file and performs basic syntax checks:
 * unbalanced parenthesis, brackets and braces, double and single quotes, etc. 
 * The program prints error messages to stdout (if there are any). */

int main(int argc, char *argv[]) {

	char *in_program_name;

	if (argc == 2) {
		in_program_name = argv[1];
	}
	else {
		in_program_name = INPUT_FILE;
	}
	check_c_syntax(in_program_name);
}

void check_c_syntax(char input_file[]) {

	char s[MAXLEN];			// String buffer for next line of the program
	int i;				// Index of character in program line
	int lnum = 0;			// Line counter (to add line number to error messages)
        int sl_comm = FALSE; 		// Flag indicating single-line comment //
	int ml_comm = FALSE;		// Flag indicating multi-line comment /* *\/
       	int ml_comm_lnum = -1;		// Line number of last opening of multi-line comment
	int squote_str = FALSE;		// Flag indicating single-quote string ''
	int squote_str_lnum = -1;	// Line number of last opening of single-quote string
	int squote_len = 0;		// Length of constant in single quotes (must be <= 1)
	int dquote_str = FALSE;		// Flag indicating double-quote string ""
	int dquote_str_lnum = -1;	// Line number of last opening of double-quote string
	int parenthesis_opened = 0;	// Number of opening parenthesis ()
	int parenthesis_closed = 0;	// Number of closing parenthesis ()
	int parenthesis_lnum = -1;	// Line number of last opening of parenthesis
	int brackets_opened = 0;	// Number of opening brackets []
	int brackets_closed = 0;	// Number of closing brackets []
	int brackets_lnum = -1;		// Line number of last opening of brackets
	int braces_opened = 0;		// Number of opening braces {}
	int braces_closed = 0;		// Number of closing braces {}
	int braces_lnum = -1;		// Line number of last opening of braces

	FILE *in_program;	// Input file with C program to analyze
	in_program = fopen(input_file, "r");

	lnum = 0;

	// Reading input file with C program line by line
	while ( fgets(s, MAXLEN, in_program)) {
		
		++lnum;
		// printf("Line number %d being processed...\n", lnum);
		// printf("%s\n", s);

		i = 0;
		// Reading characters of the line till end of the line
		while ( s[i] != '\0') {
			
			// printf("%d\n", squote_len);
			// For simplicity this program doesn't take into account \' and \" escape-sequences with quotes

			// For simplicity we assume all strings are single-lined.
			// If we are in double-quote
			if (dquote_str) {
				// Process closing double-quote
				if (s[i] == '"') {
					if (i == 0 || s[i-1] != '\\') {
						dquote_str = FALSE; 
						dquote_str_lnum = -1;
					}
				} 
			}
			
			// There can be only one character in single-quotes
			// If we are in single-quote
			else if (squote_str) {
				// printf("%c\n", s[i]);
				// Process closing single-quote
				if (s[i] == '\'') {
					if (i == 0 || s[i-1] != '\\') {
						squote_str = FALSE;
						squote_str_lnum = -1;
					}
				}
				else {
					++squote_len;
					if (squote_len > 2) { 
						/* Replace this code to a function call, 
						 * or return struct with error code end text of error message */
						printf("Error in line %d: too long single-quote string - %s\n", lnum, s);

						// Need to handle case with c = '\''
					}
				}
			}
			
			// If we are in multi-line comment
			else if (ml_comm) {
				// Check if we found end of multi-line comment
				if (s[i] == '*' && s[i+1] == '/') {
					ml_comm = FALSE;
					++i;
				}
			}

			// If we are in single-line comment
			else if (sl_comm) {
				if (s[i] == '\n') {
					sl_comm = FALSE;
				}
			}
			

			// Else (we are in normal text of program)
			
			// Process double-quote
			else if (s[i] == '"') {
				dquote_str = TRUE;
				dquote_str_lnum = lnum;
			}

			// Process single-quote
			else if (s[i] == '\'') {
				squote_str = TRUE;
				squote_str_lnum = lnum;
				squote_len = 0;
			}

			// Process start of multi-line comment
			else if (s[i] == '/' && s[i+1] == '*') {
				ml_comm = TRUE;
				ml_comm_lnum = lnum;
				++i;
			}

			// Process end of multi-line comment
			else if (s[i] == '*' && s[i+1] == '/') {
				/* If we are here, we didn't match ml_comm condition above.
				 * It means we met end of multi-line comment without meeting its start, that's error */
				printf("Error in line %d: end of multi-line comment before start of multi-line comment - %s\n", lnum, s);
			}

			// Process start of single-line comment
			else if (s[i] == '/' && s[i+1] == '/') {
				sl_comm = TRUE;
				++i;
			}

			// Process opening parenthesis
			else if (s[i] == '(') {
				++parenthesis_opened;
				parenthesis_lnum = lnum;
			}

			// Process closing parenthesis
			else if (s[i] == ')') {
				if (parenthesis_opened > parenthesis_closed) {
					++parenthesis_closed;
				}
				else {
					printf("Error in line %d: closing parenthesis before opening!\n", lnum);
				}
			}

			// Process opening brackets
			else if (s[i] == '[') {
				++brackets_opened;
				brackets_lnum = lnum;
			}

			// Process closing brackets
			else if (s[i] == ']') {
				if (brackets_opened > brackets_closed) {
					++brackets_closed;
				}
				else {
					printf("Error in line %d: closing brackets before opening!\n", lnum);
				}
			}

			// Process opening braces
			else if (s[i] == '{') {
				++braces_opened;
				braces_lnum = lnum;
			}

			// Process closing braces 
			else if (s[i] == '}') {
				if (braces_opened > braces_closed) {
					++braces_closed;
				}
				else {

					printf("Error in line %d: closing braces before opening!\n", lnum);
				}
			}

			// Process all other characters in text of C program
			else {
				;
			}

			++i; // Go to the next character in the line	


		}
		
	}

	// Analyze if there any syntax errors found
	
	// Check unbalanced double quotes
	if (dquote_str)
		printf("Unbalanced double quote string in line %d!\n", dquote_str_lnum);
	
	// Check unbalanced single quotes
	if (squote_str)
		printf("Unbalanced single quote string in line %d!\n", squote_str_lnum);
	
	// Check not closed multi-line comments
	if (ml_comm)
		printf("Not closed multi-line comment started in line %d!\n", ml_comm_lnum);

	// Check unbalanced parenthesis
	if (parenthesis_opened != parenthesis_closed)
		printf("Unbalanced parenthesis in line %d!\n", parenthesis_lnum);
	
	// Check unbalanced brackets
	if (brackets_opened != brackets_closed)
		printf("Unbalanced brackets in line %d!\n", brackets_lnum);
	
	// Check unbalanced braces
	if (braces_opened != braces_closed)
		printf("Unbalanced braces in line %d!\n", braces_lnum);

	fclose(in_program); 

}
