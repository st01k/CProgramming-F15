/*	Calculate the average of the number in an array.
	   Written by:
	   Date:
*/
#include <stdio.h>

//	Function Declaration
double average (int ary[ ]);

int main (void)
{
//	Local Declarations
	double ave;
	int    base[5] = {3, 7, 2, 4, 5};

//	Statement
	ave = average(base);
	printf("Average is: %lf\n", ave);
	return 0;
}	// main

/*	==================== average ====================
	Calculate and return average of values in array.
	   Pre  Array contains values
	   Post Average calculated and returned
*/
double average (int ary[ ])
{
//	Local Declarations
	int sum = 0;

//	Statement
	for (int i = 0; i < 5; i++)
	     sum += ary[i];

	return (sum / 5.0);
}	// average

/*	Results:
Average is: 4.200000
*/