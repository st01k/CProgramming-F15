/*	Test driver for Reading Strings.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{

//	Statements 
{	// Read Month
	#define FLUSH while (getchar() != '\n')
	char month[10];

	printf("Please enter a month. ");
	scanf("%9s", month); 
	FLUSH; 
	
	printf("You entered: %s\n", month);
}	// Read Month

	return 0;
}	// main

/*	Results:
Please enter a month. July
You entered: July
*/