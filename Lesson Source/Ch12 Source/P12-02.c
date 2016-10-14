/*	This program uses structures to simulate the 
	multiplication of fractions.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	Global Declarations
	typedef  struct
	   {
	    int numerator;
	    int denominator;
	   } FRACTION;

int main (void)
{
//	Local Declarations 
	FRACTION  fr1;
	FRACTION  fr2;
	FRACTION  res;

//	Statements 
	printf("Key first fraction in the form of  x/y: "); 
	scanf ("%d /%d", &fr1.numerator, &fr1.denominator);
	printf("Key second fraction in the form of x/y: "); 
	scanf ("%d /%d", &fr2.numerator, &fr2.denominator);

	res.numerator   = fr1.numerator   * fr2.numerator;
	res.denominator = fr1.denominator * fr2.denominator;

	printf("\nThe result of %d/%d * %d/%d is %d/%d", 
	       fr1.numerator, fr1.denominator, 
	       fr2.numerator, fr2.denominator, 
	       res.numerator, res.denominator); 
	return 0;
}	// main 

/*	Results:
Key first fraction in the form of x/y:  2/6
Key second fraction in the form of x/y: 7/4

The result of 2/6 * 7/4 is 14/24
*/