/*	Test Driver for continue flags. Program should be run twice, 
	first with readAverage1 and then with readAverage2 to verify
	that the results are the same.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdbool.h>

//	Function Declarations
float readAverage1 (void);
float readAverage2 (void);

int main (void)
{
//	Local Declarations
	bool breakFlag = true;
	int  x = 0;
	int  y = 0;
	int  z = 0;
	
//	Statements
	printf("Please enter 5 integers: ");
	// Change to readAverage2
	printf("\nAverage 1: %f\n", readAverage2());
	return 0; 
}	// main

/*	A function with a continue statement.
		Pre  Nothing
		Post Nothing
*/
float readAverage1 (void)
{
//	Local Declarations 
	int   count = 0;
	
	int   n;
	float sum = 0;

//	Statements 
	while(scanf("%d",&n) != EOF)
	   {
	    if (n == 0)
	       continue;
	    sum += n;
	    count++;
	   }  // while 

	return (sum / count);
}	// readAverage 

/*	A function without a continue statement.
		Pre  Nothing
		Post Nothing
*/
float readAverage2 (void)
{
//	Local Declarations 
	int   count = 0;

	int   n;
	float sum = 0;

//	Statements 
	while(scanf("%d",&n) != EOF)
	    {
	    if (n != 0)
	       {
	        sum += n;
	        count++;
	       } // if 
	      } // while 
	return (sum / count);
}	// readAverage 

/*	Results:
With readAverage1
	Please enter 5 integers: 1 4 7 2 5
	^d
	Average 1: 3.800000

with readAverage2
	Please enter 5 integers: 1 4 7 2 5
	^d
	Average 1: 3.800000
*/