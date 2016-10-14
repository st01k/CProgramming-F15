/*	This program uses structures to multiply fractions.
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

//	Function Declarations
FRACTION getFr   (void);
FRACTION multFr  (FRACTION fr1, FRACTION fr2); 
void     printFr (FRACTION fr1, FRACTION fr2,
                  FRACTION result);

int main (void)
{
//	Local Declarations
	FRACTION fr1;
	FRACTION fr2;
	FRACTION res;

//	Statements
	fr1 = getFr  ();
	fr2 = getFr  ();
	res = multFr (fr1, fr2);
	printFr (fr1, fr2, res);
	return 0;
}	// main

/*	==================== getFr ==================== 
	Get two integers from the keyboard, make & return 
	a fraction to the main program.
	   Pre   nothing
	   Post  returns a fraction
*/
FRACTION getFr (void)
{
// Local Declarations
	FRACTION fr;

// Statements
	printf("Write a fraction in the form of x/y: ");
	scanf ("%d/%d", &fr.numerator, &fr.denominator);
	return fr;
}	// getFraction

/*	==================== multFr ==================== 
	Multiply two fractions and return the result.
	   Pre   fr1 and fr2 are fractions
	   Post  returns the product 
*/
FRACTION multFr (FRACTION fr1, FRACTION fr2)
{
//	Local Declaration
	FRACTION res;

//	Statements
	res.numerator   = fr1.numerator   * fr2.numerator;
	res.denominator = fr1.denominator * fr2.denominator;
	return res;
} // multFr

/*	==================== printFr ====================
	Prints the value of the fields in three fractions.
	   Pre   two original fractions and the product 
	   Post  fractions printed 
*/
void  printFr  (FRACTION fr1,  FRACTION fr2,
                FRACTION res)
{
//	Statements
	printf("\nThe result of %d/%d * %d/%d is %d/%d\n",
	          fr1.numerator, fr1.denominator,
	          fr2.numerator, fr2.denominator,
	          res.numerator, res.denominator);
	return;
}	// printFractions
//	================== End of Program ==================

/*	Results:
Write a fraction in the form of x/y: 4/3
Write a fraction in the form of x/y: 6/7

The result of 4/3 * 6/7 is 24/21
*/