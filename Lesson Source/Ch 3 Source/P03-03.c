/*	This program demonstrates binary expressions.
	   Written by:
	   Date: 
*/
#include <stdio.h>
int main (void)
{
//	Local Declarations 
	int   a = 17;
	int   b = 5;
	float x = 17.67;
	float y = 5.1;

//	Statements 
	printf("Integral calculations\n");
	printf("%d + %d  = %d\n", a, b, a + b);
	printf("%d - %d  = %d\n", a, b, a - b);
	printf("%d * %d  = %d\n", a, b, a * b);
	printf("%d / %d  = %d\n", a, b, a / b);
	printf("%d %% %d  = %d\n", a, b, a % b);
	printf("\n");

	printf("Floating-point calculations\n");
	printf("%f + %f  = %f\n", x, y, x + y);
	printf("%f - %f  = %f\n", x, y, x - y);
	printf("%f * %f  = %f\n", x, y, x * y);
	printf("%f / %f  = %f\n", x, y, x / y);
	return 0;
}	// main 

/*	Results:
Integral calculations
17 + 5 = 22
17 - 5 = 12
17 * 5 = 85
17 / 5 = 3
17 % 5 = 2

Floating-point calculations
17.670000 + 5.100000  = 22.770000
17.670000 - 5.100000  = 12.570000
17.670000 * 5.100000  = 90.116997
17.670000 / 5.100000  = 3.464706
*/