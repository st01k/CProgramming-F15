/*	This program extracts and adds the two least 
	significant digits of an integer.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	 Function Declarations 
int addTwoDigits (int num);
int firstDigit   (int num);
int secondDigit  (int num);

int main (void)
{
//	Local Declarations 
	int  number;
	int  sum;

//	Statements 
	printf("Enter an integer: ");
	scanf ("%d", &number);

	sum = addTwoDigits (number);
	printf ("\nSum of last two digits is: %d", sum);

	return 0;
}	// main 

/* ================== addTwoDigits ================== 
	 Adds the first two digits of an integer.
	    Pre  num contains an integer
	    Post returns sum of least significant digits
*/
int addTwoDigits (int number)
{
//	Local Declarations 
	int result;

//	Statements 
	result = firstDigit(number) + secondDigit(number);
	return result;
}	// addTwoDigits 

/* ================== firstDigit ================= 
	Extract the least significant digit of an integer.
	   Pre   num contains an integer
	   Post  Returns least significant digit.
*/
int firstDigit (int num)
{
//	Statements 
	return (num % 10);
}	// firstDigit 

/* ================= secondDigit ================= 
	Extract second least significant (10s) digit
	   Pre   num is an integer
	   Post  Returns digit in 10s position
*/
int secondDigit (int num)
{
//	Local Declarations 
	int  result;

//	Statements 
	result = (num / 10) % 10;
	return result;
}	// secondDigit 

/*	Results:
Run 1
	Enter an integer: 23
	Sum of last two digits is: 5

Run 2
	Enter an integer: 8
	Sum of last two digits is: 8
*/