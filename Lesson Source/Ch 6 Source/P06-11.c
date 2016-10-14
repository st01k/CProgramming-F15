/*	Print number series from 1 to a user-specified limit 
	in the form of a rectangle.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations 
	int limit;

//Statements 
	// Read limit 
	printf("Please enter a number between 1 and 9: ");
	scanf("%d", &limit);

	for (int row = 1; row <= limit; row++)
	   {
	    for (int col = 1; col <= limit; col++)
	         if (row >= col)
	            printf("%d", col);
	         else
	            printf("*");
	    printf("\n");
	   } // for row ... 
	return 0;
}	// main 

/*	Results:
Please enter a number between 1 and 9: 6
1*****
12****
123***
1234**
12345*
123456
*/