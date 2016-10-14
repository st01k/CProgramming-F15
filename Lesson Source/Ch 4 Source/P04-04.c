/*	This program prints the first digits of an integer 
	read from the keyboard 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	 Function Declarations 
	int firstDigit (int num);

int main (void)
{
//	Local Declarations 
	int number;
	int digit;

//	Statements 
	printf("Enter an integer: ");
	scanf ("%d", &number);

	digit = firstDigit (number);
	printf("\nLeast significant digit is: %d\n", digit);

	return 0;
}	// main 

/* ================= firstDigit ================== 
 	This function extracts the least significant digit 
	of an integer.
	   Pre   num contains an integer
	   Post  Returns least significant digit.
*/
int firstDigit (int num)
{
//	Statements 
	return (num % 10);
}	// firstDigit 

/*	Results:
Enter an integer: 27

Least significant digit is: 7
*/