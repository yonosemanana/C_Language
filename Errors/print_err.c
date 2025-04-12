#include <stdio.h>
#include <errno.h>
#include <string.h>

int main (int argc, char *argv[]) {
	int error_num;

	error_num = ENOENT;
	printf("ENOENT - %s\n", strerror(error_num));

	errno = EACCES;
	perror("EACCES - ");
	
	FILE *f_non_exist = fopen("non-existing-file.txt", "r");
	perror("File opening failed");


}
