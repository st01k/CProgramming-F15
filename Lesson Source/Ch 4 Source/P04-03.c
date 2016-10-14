/*	This program reads a number and prints its square.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	Function Declarations 
int  getNum   (void);
int  sqr      (int x);
void printOne (int x);

int main (void)
{
//	Local Declarations 
	int a;
	int b;

//	Statements 
	// Get number and square it 
	a = getNum ();

	// Square the number just read 
	b = sqr (a);
	
	// Now print it 
	printOne(b);

	return 0;
}	// main 

/*	=================== getNum ===================
	Read number from keyboard and return it.
	   Pre   nothing
	   Post  number read and returned
*/
int getNum (void)
{
//	Local Declarations 
	int numIn;
	
//	Statements 
	printf("Enter a number to be squared: ");
	scanf ("%d", &numIn);
	return numIn;
}	// getNum 

/*	=================== sqr ===================
	Return the square of the parameter.
	   Pre   x contains number to be squared
	   Post  squared value returned
*/
int sqr (int x)
{
//	Statements 
	return (x * x);
}	// sqr 

/*	=================== printOne ===================
	Print one integer value.
	   Pre   x contains number to be printed
	   Post  value in x printed
*/
void printOne (int x)
{
//	Statements 
	printf("The value is: %d\n", x);
	return;
}	// printOne 

/*	Results:
Enter a number to be squared: 81
The value is: 6561
*/