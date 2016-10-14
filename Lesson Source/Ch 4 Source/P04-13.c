/*	This program adds two integers read from the 
	keyboard and prints the results.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	 Function Declarations 
void getData  (int* a, int* b); 

int main (void)
{
//	Local Declarations
	int  a;
	int  b;

//	Statements 
	getData (&a, &b);

	printf("**main:    a = %d; b = %d\n", a, b); 

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

	printf("**getData: a = %d; b = %d\n", *a, *b);
	return;
}	// getData 

/*	Results: 
Please enter two integer numbers: 8 13
**getData: a = 8; b = 13
**main:    a = 8; b = 13
*/