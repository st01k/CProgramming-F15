/*	Test driver for sumEOF.
	   Written by:
	   Date:
*/
#include <stdio.h>

/*	Prototype Declarations */
int sumEOF (void);

int main (void)
{
/*	Statements */
	printf("\n\nThe sum is %d\n", sumEOF());
	return 0;
}	/* main */

/*	Read a series of numbers, terminated by EOF, and  
	return their sum to the calling program.
	   Pre   nothing
	   Post  data read and sum returned
*/
int sumEOF (void)
{
//	Local Declarations 
	int nmbr;
	int sum;

//	Statements 
	sum = 0;
	printf ("Please enter an integer:    ");

	while (scanf("%d", &nmbr) != EOF)
	   {
	    sum += nmbr;
	    printf("Next integer <EOF> to stop: ");
	   } // while 
	return sum;
}	// sumEOF 

/*	Results:
	
	Please enter an integer:    1
	Next integer <EOF> to stop: 2
	Next integer <EOF> to stop: 3
	Next integer <EOF> to stop: ^d

	The sum is 6
*/