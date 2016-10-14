/*	Test driver (compile only) for program fragment.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
//	Local Definitions
	int unitsSold;
	
//	Statement

#define FLUSH while (getchar() != '\n')
// ...
	printf("\nPlease enter Number of Units Sold: ");
	while (scanf("%d", &unitsSold) != 1)
	   {
	    // scanf returns 1 if number read corrrectly 
	    FLUSH;
	    printf("\aInvalid number. Please re-enter: ");
	   } // while 

	return 0;
}	// main