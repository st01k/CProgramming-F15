/*	Generate a real random series in the range 0 to 1.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
//	Local Declarations
	float x;

//	Statements
	srand(time(NULL));

	x = (float)rand() / RAND_MAX;
	printf("%f", x);
	x = (float)rand() / RAND_MAX;
	printf(" %f", x);
	x = (float)rand() / RAND_MAX;
	printf(" %f\n", x);

	return 0;
}	// main

/*	Results:
0.782006 0.264260 0.348460 
*/