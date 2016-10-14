/*	Calculate average of numbers in variable-length 
	array.
	   Written by:
	   Date:
*/
#include <stdio.h>

//	Function Declaration
double average (int size, int ary[*]);

int main (void)
{
//	Local Declarations
	int    size;
	double ave;
	
//	Statements
	printf("How many numbers do you want to average? ");
	scanf ("%d", &size);
	
	// Create and fill variable-length array
	{
	 // Local Declaration
	 int ary[size];
	 
	 // Fill array
	 for (int i = 0; i < size; i++)
	     {
	      printf("Enter number %2d: ", i + 1);
	      scanf ("%d", &ary[i]);
         } // for
     ave = average(size, ary);
	} // Fill array block

	printf("Average is: %lf", ave);	 		
	return 0;
}	// main

/*	==================== average ====================
	Calculate and return average of values in array.
	   Pre  Array contains values
	   Post Average calculated and returned
*/
double average (int size, int ary[*])
{
//	Local Declarations
	int sum = 0;
	double ave;

//	Statement
	for (int i = 0; i < size; i++)
	     sum += ary[i];

	ave = (double)sum / size;
	return ave;
}	// average

/*	Results
How many numbers do you want to average? 5
Enter number  1: 3
Enter number  2: 6
Enter number  3: 9
Enter number  4: 2
Enter number  5: 8
Average is: 5.600000
*/