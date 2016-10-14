/*	Print number series from 1 to user-specified limit.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void)
{
//	Local Declarations 
	int limit;

//	Statements 
	printf ("\nPlease enter the limit: ");
	scanf ("%d", &limit);
	for (int i = 1; i <= limit; i++)
	   printf("\t%d\n", i);
	return 0;
}	// main

/*	Results:
Please enter the limit: 3
 1
 2
 3
*/