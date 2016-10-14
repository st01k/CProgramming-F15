/*	Demonstrate the use of the time function to generate
	a temporal random number series.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
//	Statements
	srand(time(NULL));              // Seed temporally

	printf("%d\n", rand());
	printf("%d\n", rand());
	printf("%d\n", rand());

	return 0;
}	// main

/*	Results:
First Run
   9641
   16041
   6350
Second Run
   31390
   31457
   21438
*/