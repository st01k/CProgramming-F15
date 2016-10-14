/*	Demonstrate the use of fgets in a program
	   Written by: 
	   Date: 
*/
#include <stdio.h> 

int main (void) 
{
//	Local Declarations
	char str[81]; 

//	Statements
	printf("Please enter a string: ");
	fgets (str, sizeof (str), stdin); 
	printf("Here is your string: \n\t%s", str);
	return 0; 
}	// main

/*	Results:
Please enter a string: Now is the time for all students
Here is your string:
	Now is the time for all students
*/