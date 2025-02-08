#include <stdio.h>
#include <ctype.h>

/* Convert string to double */
double myatof(char s[]) {
	int i, k, sign;
	double exp, exp_sign, exp_mul;
	double val, power;

	// Skip leading spaces
	for(i = 0; s[i] == ' '; ++i)
		;
	//printf("%d\n", i);
	
	// Handle sign
	sign = 1;
	if (s[i] == '-')
		sign = -1;
	//printf("sign = %d\n", sign);	
	
	if (s[i] == '-' || s[i] == '+')
		++i;

	for (val = 0.0; isdigit(s[i]); ++i) 
		val = 10.0 * val + s[i] - '0'; 

	if (s[i] == '.')
		++i;

	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + s[i] - '0';
		power *= 10;
	}
	//printf("%f\n", sign * val / power);
	//printf("i = %d, s[i] = %c\n", i, s[i]);

	if (s[i] == 'e' || s[i] == 'E')
		++i;
	
	exp_sign = 10.0;
	if (s[i++] == '-')
		exp_sign = 0.1;
	//printf("%f\n", exp_sign);
	
	for(exp = 0; isdigit(s[i]); ++i)
		exp = 10 * exp + s[i] - '0';
	
	exp_mul = 1.0;
	for(k = 0; k < exp; k++)
		exp_mul *= exp_sign;

	return sign * val / power * exp_mul;




}
