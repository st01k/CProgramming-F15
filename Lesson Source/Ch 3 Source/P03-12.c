/*	This program prompts the user to enter an angle 
	measured in radians and converts it into degrees.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define DEGREE_FACTOR 57.295779

int main (void)
{
//	Local Declarations 
	double  radians;
	double  degrees;

//	Statements 
	printf("Enter the angle in radians: ");
	scanf("%lf", &radians);

	degrees = radians * DEGREE_FACTOR;
	
	printf("%6.3f radians is %6.3f degrees\n", 
	         radians, degrees);
	return 0;
}	// main 

/*	Results:
Enter the angle in radians: 1.57080
 1.571 radians is 90.000 degrees
*/