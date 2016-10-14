/*	Test driver for smallest to EOF function
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <limits.h>

/*	Prototype Declarations */
int smallestEOF (void);

int main (void)
{
/*	Statements */
	printf("\n\nSmallest number is: %d", smallestEOF());
	return 0;
}	/* main */

/*	Read a series of numbers, terminated by EOF, and 
	pass the smallest to the calling program. 
	   Pre   nothing 
	   Post  data read and smallest returned 
*/
int smallestEOF (void)
{
//	Local Declarations 
	int numIn;
	int smallest;

//	Statements 
	smallest = INT_MAX;        // requires <limits.h>

	printf("Please enter an integer: ");

	while (scanf("%d", &numIn) != EOF)
	   {
	    if (numIn < smallest)
	        smallest = numIn;
	    printf("Enter next integer <EOF> to stop: ");
	   } // while 
	return smallest;
}	 // smallestEOF 

/*	Results:
Please enter an integer: 18
Enter next integer <EOF> to stop: 21
Enter next integer <EOF> to stop: 14
Enter next integer <EOF> to stop: 13
Enter next integer <EOF> to stop: 2
Enter next integer <EOF> to stop: 3
Enter next integer <EOF> to stop: 4
Enter next integer <EOF> to stop: 

Smallest number is: 2
*/