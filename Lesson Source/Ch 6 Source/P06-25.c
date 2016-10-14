/*	Test driver for recursive factorial.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdbool.h>

/*	Prototype Declarations */
long factorial (int n);

int main (void)
{
/*	Statements */
	printf("Factorial 5 is: %d\n", factorial (5));
	return 0;
}	/* main */

/*	Calculate factorial of a number using recursion. 
	There is no test that the result fits in a long. 
	   Pre   n is the number being raised factorially 
	   Post  result is returned 
*/
long factorial (int n)
{
//	Statements 
	if (n == 0)
	   return 1;
	else
	   return (n * factorial (n - 1));
} // factorial 

/*	Results:
Factorial 5 is: 120
*/