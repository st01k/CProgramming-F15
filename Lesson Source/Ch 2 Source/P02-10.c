/*	Demonsrate complex number arithmetic.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <math.h>
#include <complex.h>

int main (void)
{
//	Local Declarations
	double complex x = 3 + 4 * I;
	double complex y = 3 - 4 * I;
	double complex sum;
	double complex dif;
	double complex mul;
	double complex div;

//	Statements
	sum = x + y;
	dif = x - y;
	mul = x * y;
	div = x / y;

	printf("%f %f %f %f\n", creal(sum), cimag(sum),
	                        cabs(sum),  carg(sum));
	printf("%f %f %f %f\n", creal(dif), cimag(dif), 
	                        cabs(dif),  carg(dif));
	printf("%f %f %f %f\n", creal(mul), cimag(mul), 
	                        cabs(mul),  carg(mul));
	printf("%f %f %f %f\n", creal(div), cimag(div), 
	                        cabs(div),  carg(div));
	return 0;
}	// main

/*	Results: 
6.000000 0.000000 6.000000 0.000000
0.000000 8.000000 8.000000 1.570796
25.000000 0.000000 25.000000 0.000000
-0.280000 0.960000 1.000000 1.854590
*/