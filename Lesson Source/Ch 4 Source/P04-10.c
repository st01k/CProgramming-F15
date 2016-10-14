/*	Demonstrate the use of the srand function to generate
	a pseudorandom number series.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
//	Statements
	srand(997);                  // Seed temporally

	printf("%d\n", rand());
	printf("%d\n", rand());
	printf("%d\n", rand());

	return 0;
}	// main

/*	Results:
First Run
   10575
   22303
   4276
Second Run
   10575
   22303
   4276
*/