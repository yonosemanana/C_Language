#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

#define MAXLEN		1000

#define UCHAR_MIN	0
#define UINT_MIN	0
#define ULONG_MIN	0


int main(void) {
	char msg_min[] = "Minimum value of type '%s' is: ";
	char msg_max[] = "Maximum value of type '%s' is: ";
	char msg_epsilon[] = "For type '%s' the smallest number 'x' such as 1.0 + 'x' != 1.0 is: ";
	
	int n_int_types = 8;
	int n_float_types = 2;

	char *c_int_types[] = {"char", "short", "int", "signed char", "unsigned char", "unsigned int", "unsigned long", "long"};
	double c_int_types_minlimits[] = {CHAR_MIN, SHRT_MIN, INT_MIN, SCHAR_MIN, UCHAR_MIN, UINT_MIN, ULONG_MIN, LONG_MIN};
	double c_int_types_maxlimits[] = {CHAR_MAX, SHRT_MAX, INT_MAX, SCHAR_MAX, UCHAR_MAX, UINT_MAX, ULONG_MAX, LONG_MAX};

	char *c_float_types[] = {"float", "double"};
	double c_float_types_minlimits[] = {FLT_MIN, DBL_MIN};
	double c_float_types_maxlimits[] = {FLT_MAX, DBL_MAX};
	double c_float_types_epsilons[] = {FLT_EPSILON, DBL_EPSILON};

	for (int i = 0; i < n_int_types; ++i) {
		printf(msg_min, c_int_types[i]);
		printf("%.0f\n", c_int_types_minlimits[i]);
		printf(msg_max, c_int_types[i]);
		printf("%.0f\n", c_int_types_maxlimits[i]);
		printf("\n");
	}
	
	for (int i = 0; i < n_float_types; ++i) {
		printf(msg_min, c_float_types[i]);
		printf("%.38lf\n", c_float_types_minlimits[i]);
		printf(msg_max, c_float_types[i]);
		printf("%lf\n", c_float_types_maxlimits[i]);
		printf(msg_epsilon, c_float_types[i]);
		printf("%.11lf\n", c_float_types_epsilons[i]);
		printf("\n");
	}
	
	

}
