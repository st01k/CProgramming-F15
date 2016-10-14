/*	Example of postfix increment.
	   Written by:
	   Date:
*/
#include <stdio.h>
int main (void)
{
//	Local Declarations 
	int a;

//	Statements 
	a = 4;
	printf("value of a    : %2d\n", a);
	printf("value of a++  : %2d\n",   a++);
	printf("new value of a: %2d\n\n", a);
	return 0;
}	// main

/*	Results:
value of a    :  4
value of a++  :  4
new value of a:  5
*/