/*	Test driver for any smallest to EOF function
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdbool.h>

/*	Prototype Declarations */
bool anyPositiveEOF (void);

int main (void)
{
/*	Statements */
	if (anyPositiveEOF())
	   printf("\nA positive number found\n");
	else
	   printf("\nAll numbers negative\n");
	return 0;
}	/* main */

/*	Read number series to determine if any positive.
	   Pre  nothing 
	   Post return true if any number > zero
	        return false if all numbers <= zero
*/
bool anyPositiveEOF (void)
{
//	Local Declarations 
	bool anyPositive = false;
	int  numIn;

//	Statements 
	printf("Determine if any number are positive\n");
	printf("Enter first number: ");
	while (scanf("%d", &numIn) != EOF)
	   {
	    anyPositive = numIn > 0;
	    if (anyPositive)
	        return true;
	    printf("Enter next number:  ");
	   } // while 
	return false;
} // anyPositiveEOF 

/*	Results:
First Run:
	Determine if any number are positive
	Enter first number: -1
	Enter next number:  -2
	Enter next number:  -3
	Enter next number:  -4
	Enter next number:  0
	Enter next number:  ^d
	All numbers negative
Second Run:
	Determine if any number are positive
	Enter first number: -1
	Enter next number:  -2
	Enter next number:  -3
	Enter next number:  4

	A positive number found
*/