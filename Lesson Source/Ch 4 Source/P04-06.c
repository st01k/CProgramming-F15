/*	This program reads long integers from the keyboard 
	and prints them with leading zeros in the form 
	123,456 with a comma between 3rd & 4th digit.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
//	Function Declarations 
void printWithComma (long num);

int main (void)
{
//	Local Declarations 
	long  number;

//	Statements 
	printf("\nEnter a number with up to 6 digits: ");
	scanf ("%ld", &number);
	printWithComma (number);

	return 0;
}	// main 

/* =============== printWithComma ================ 
	This function divides num into two three-digit 
	numbers and prints them with a comma inserted.
	   Pre   num is a six digit number
	   Post  num has been printed with a comma inserted
*/
void printWithComma (long num)
{
//	Local Declarations 
	int  thousands;
	int  hundreds;

//	Statements 
	thousands  = num / 1000;
	hundreds   = num % 1000;

	printf("\nThe number you entered is \t%03d,%03d", 
	         thousands, hundreds);
	return; 
}	// printWithComma 

/*	Results:
Run 1
	Enter a number with up to 6 digits: 123456

	The number you entered is       123,456
Run 2
	Enter a number with up to 6 digits: 12

	The number you entered is       000,012
*/