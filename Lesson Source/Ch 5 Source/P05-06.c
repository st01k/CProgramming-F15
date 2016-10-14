/*	Test Driver to demonstrate switch statement.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations
	int printFlag = 2;
	
//	Program fragment to demonstrate switch
	switch (printFlag)
	   {
	    case 1:  printf("This is case 1\n");
	             
	    case 2:  printf("This is case 2\n");
	             
	    default: printf("This is default\n");
	   } // switch 
	return 0;
}	// main 

/*	Results
printFlag is 1:
	This is case 1
	This is case 2
	This is default
printFlag is 2:
	This is case 2
	This is default
printFlag is 8
	This is default
*/