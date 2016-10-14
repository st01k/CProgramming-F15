/*	This program demonstrates that one function can be 
	called multiple times.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	Function Declarations 
void printOne (int x);

int main (void)
{
//	Local Declarations 
	int a;

//	Statements 
	a = 5;                             // First call
	printOne (a);
	
	a = 33;
	printOne (a);                      // Second call

	// Done. Return to operating system. 
	return 0;
}	// main 

/*	=================== printOne ===================
	Print one integer value.
	   Pre   x contains number to be printed
	   Post  value in x printed
*/
void printOne (int x)
{
//	Statements 
	printf("%d\n", x);
	return;
}	// printOne 

/*	Results:
5
33
*/