/*	Demonstrates the results of relational operators.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations 
	int a = 5;
	int b = -3;

//	Statements *
	printf(" %2d <  %2d is %2d\n", a, b,  a <  b);
	printf(" %2d == %2d is %2d\n", a, b,  a == b);
	printf(" %2d != %2d is %2d\n", a, b,  a != b);
	printf(" %2d >  %2d is %2d\n", a, b,  a >  b);
	printf(" %2d <= %2d is %2d\n", a, b,  a <= b);
	printf(" %2d >= %2d is %2d\n", a, b,  a >= b);
	return 0;
}	// main 

/*	Results:
5 <  -3 is  0
5 == -3 is  0
5 != -3 is  1
5 >  -3 is  1
5 <= -3 is  0
5 >= -3 is  1
*/