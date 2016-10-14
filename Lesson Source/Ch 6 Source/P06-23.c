/*	Test driver for all positive numbers.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdbool.h>

/*	Prototype Declarations */
bool allPositiveEOF (void);

int main (void)
{
/*	Statements */
	if (allPositiveEOF())
	   printf("\nAll numbers positive\n");
	else
	   printf("A non-positive number found\n");
	return 0;
}	/* main */

/*	Read number series, and determine if all are positive.
	   Pre   nothing
	   Post  return true if all numbers > zero
	         return false if any numbers <= zero
*/
bool allPositiveEOF (void)
{
//	Local Declarations 
	bool allPositive = true;
	int  numIn;

//	Statements 
	printf("Determine if all numbers are positive\n");
	printf("Enter first number: ");
	while (allPositive && (scanf("%d", &numIn) != EOF))
	   {
	    allPositive =  numIn > 0;
	    if (!allPositive)
	        return false;
	    printf("Enter next number:  ");
	   } // while 
	return true;
} // allPositiveEOF 

/*	Results:
First Run:
	Determine if all numbers are positive
	Enter first number: 1
	Enter next number:  2
	Enter next number:  3
	Enter next number:  0
	A non-positive number found
Second Run:
	Determine if all numbers are positive
	Enter first number: 1
	Enter next number:  2
	Enter next number:  3
	Enter next number:  ^d
	All numbers positive
*/