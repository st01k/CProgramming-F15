/*	Test driver for powers.
	   Written by:
	   Date:
*/
#include <stdio.h>

/*	Prototype Declarations */
int powers (int base, int exp);

int main (void)
{
/*	Statements */
	printf("3 power 4 is: %d\n", powers(3, 4));
	return 0;
}	/* main */

/*	Raise base to an integral power, exp. If the 
	exponent is zero, return 1.
	   Pre   base & exp are both positive integer values 
	   Post  return either (a) the result of raising the  
	           base to the exp power
	         or (b) zero if the parameters are invalid
*/
int powers (int base, int exp)
{
//	Local Declarations 
	int result = 1;

//	Statements 
	if (base < 1 || exp < 0)
	   // Error Condition 
	   result = 0;
	else
	   for  (int i = 1; i <= exp; i++)
	         result *= base;
	return result;
}	// powers 

/*	Results:
3 power 4 is: 81
*/