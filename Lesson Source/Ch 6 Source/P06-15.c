/*	Convert a binary number to a decimal number.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdbool.h>

//	Function Declarations 
long long getNum          (void);
long long binaryToDecimal (long long binary);
long long powerTwo        (long long num);
long long firstDigit      (long long num);
bool      validateBinary  (long long binary);

int main (void)
{
//	Local Declarations 
	long long binary;
	long long decimal;

//	Statements 
	binary   = getNum ();
	decimal  = binaryToDecimal (binary);
	printf("The binary number was: %lld", binary);
	printf("\nThe decimal number is: %lld", decimal);
	return 0;
}	// main

/*	===================== getNum ====================
	This function reads and validates a binary number 
	from the keyboard.
	   Pre   nothing
	   Post  a valid binary number is returned
*/
long long getNum (void) 
{
//	Local Declarations 
	bool      isValid;
	long long binary;

//	Statements 
	do
	 {
	  printf("Enter a binary number (zeros and ones): ");
	  scanf ("%lld", &binary);
	  isValid = validateBinary (binary);
	  if (!isValid)
	     printf("\a\aNot binary. Zeros/ones only.\n\n");
	 } while (!isValid);
	return binary;
} // getNum 

/*	================ binaryToDecimal ================== 
	Change a binary number to a decimal number. 
	  Pre  binary is a number containing only 0 or 1
	  Post returns decimal number
*/
long long binaryToDecimal (long long binary)
{
//	Local Declarations 
	long long  decimal;

//	Statements 
	decimal = 0;
	for (int i = 0; binary != 0; i++)
	    {
	     decimal += firstDigit (binary) * powerTwo (i);
	     binary /= 10;
	    } // for i 
	return decimal;
} // binaryToDecimal 

/*	================= validateBinary ================== 
	Check the digits in a binary number for only 0 and 1.
	   Pre   binary is a number to be validated 
	   Post  returns true if valid; false if not 
*/
bool validateBinary (long long binary)
{
//	Statements 
	while (binary != 0)
	   {
	    if (!(binary % 10 == 0 || binary % 10 == 1))
	        return false;
	    binary /= 10;
	   } // while 
	return true;
}	// validateBinary 

/*	==================== powerTwo ====================
	This function raises 2 to the power num 
	   Pre   num is exponent
	   Post  Returns 2 to the power of num
*/
long long powerTwo (long long num)
{
//	Local Declarations 
	long long  power = 1;

//	Statements 
	for    (int i = 1; i <= num; i++) 
	         power *= 2;
	return power;
}	   // powerTwo 

/*	================== firstDigit ================== 
	This function returns the right most digit of num 
	   Pre   the integer num
	   Post  the right digit of num returned
*/
long long firstDigit (long long num) 
{
//	Statements 
	return (num % 10);
}	// firstDigit 

/*	Results:
Enter a binary number (zeros and ones): 10001
The binary number was: 10001 
The decimal number is: 17
*/