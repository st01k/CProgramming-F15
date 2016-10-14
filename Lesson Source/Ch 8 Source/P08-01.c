/*	Test driver for program P08-01.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
		

//	a program fragment 
#define MAX_SIZE 25

//	Local Declarations 
	// Modified to include data
	int list [MAX_SIZE] = 
		{
		 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
		 41, 42, 43, 44, 45
		};
	int numPrinted;

//	Statements 
	// ...
	numPrinted = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	   {
	    printf("%3d", list[i]);
	    if (numPrinted < 9)
	        numPrinted++;
	    else
	       {
	        printf("\n");
	        numPrinted = 0;
	        } // else 
	   } // for 

	return 0;
}	// main

/*	Results:
  1  2  3  4  5  6  7  8  9 10
 21 22 23 24 25 26 27 28 29 30
 41 42 43 44 45
*/