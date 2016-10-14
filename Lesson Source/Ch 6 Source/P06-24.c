/*	Test driver for iterative factorial.
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

/*	Calculate the factorial of a number using a loop. 
	There is no test that the result fits in a long. 
	   Pre   n is the number to be raised factorially 
	   Post  result is returned 
*/
long factorial (int n)
{
//	Local Declarations 
	long factN = 1;

//	Statements 
	for (int i = 1; i <= n; i++)
	    factN = factN * i;
	return factN;
} // factorial 

/*	Results:
Factorial 5 is: 120
*/