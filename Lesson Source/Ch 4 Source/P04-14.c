/*	This program adds two integers read 
	from the keyboard and prints the results.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	 Function Declarations 
void getData  (int* a, int* b); 
int  add      (int  a, int  b); 

int main (void)
{
//	Local Declarations
	int  a;
	int  b;
	int  sum;

//	Statements 
	getData (&a, &b);

	sum  = add  (a, b); 
	printf("**main: %d + %d = %d\n", a, b, sum);
	return 0;
}	// main 

/* ====================== getData ==================== 
	This function reads two integers from the keyboard.
	   Pre   Parameters a and b are addresses
	   Post  Data read into parameter addresses
*/
void getData (int* a, int* b)
{
	printf("Please enter two integer numbers: ");
	scanf("%d %d", a, b);
	return;
}	// getData 

/* ====================== add ====================== 
	This function adds two integers and returns the sum.
	   Pre   a and b contain values to be added
	   Post  Returns a + b
*/
int add (int a, int b)
{
//	Local Definitions
	int sum;

//	Statements
	sum = a + b;
	printf("**add:  %d + %d = %d\n", a, b, sum);

	return sum;
}	// add 

/*	Results: 
Please enter two integer numbers: 8 13
**add:  8 + 13 = 21
**main: 8 + 13 = 21
*/