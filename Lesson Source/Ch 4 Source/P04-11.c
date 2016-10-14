/*	Generate a random series in the range 10 to 20.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
//	Local Declarations
int range;

//	Statements
	srand(time(NULL));
	range = (20 - 10) + 1;

	printf("%d",    rand() % range + 10);
	printf(" %d",   rand() % range + 10);
	printf(" %d\n", rand() % range + 10);

	return 0;
}	// main

/*	Results:
10 11 16
*/