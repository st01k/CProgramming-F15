/*	This program uses structures to multiply fractions.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

//	Global Declarations
typedef struct 
        {
         int numerator;
         int denominator;
       } FRACTION;

//	Function Declarations
void getFr   (FRACTION* pFr);
void multFr  (FRACTION* pFr1, FRACTION* pFr2,
              FRACTION* pRes2);
void printFr (FRACTION* pFr1, FRACTION* pFr2,
              FRACTION* pRes);

int		main (void)
{
//	Local Declarations
	FRACTION fr1;
	FRACTION fr2;
	FRACTION res;

//	Statements
	getFr   (&fr1);
	getFr   (&fr2);
	multFr  (&fr1, &fr2, &res);
	printFr (&fr1, &fr2, &res);
	return 0;
}	// main

/*	==================== getFr ==================== 
	Get two integers from the keyboard, make & return a
	fraction to the main program.
	   Pre   pFr is pointer to fraction structure 
	   Post  fraction stored at pFr.
*/
void getFr (FRACTION* pFr)
{
//	Statements
	printf("Write a fraction in the form of x/y: ");
	scanf ("%d/%d", &pFr->numerator, &(*pFr).denominator); 
	return;
}	// getFr

/*	====================== multFr ==================== 
	Multiply two fractions and return the result.
	   Pre   fr1, fr2, pRes are pointers to fractions
	   Post  product stored at pRes
*/
void multFr  (FRACTION* pFr1, FRACTION* pFr2,
              FRACTION* pRes)
{
//	Statements
	pRes->numerator    = pFr1->numerator * pFr2->numerator; 
	pRes->denominator =
	      pFr1->denominator * pFr2->denominator;
	return;
}	// multFr

/* ====================== printFr ==================== 
	Prints the value of the fields in three fractions.
	   Pre   pointers to two fractions and their product
	   Post  fractions printed 
*/
void printFr (FRACTION* pFr1, FRACTION* pFr2,
              FRACTION* pRes)
{
//	Statements
	printf("\nThe result of %d/%d * %d/%d is %d/%d\n",
	        pFr1->numerator, pFr1->denominator,
	        pFr2->numerator, pFr2->denominator,
	        pRes->numerator, pRes->denominator);
	return;
}	// printFr
//	================== End of Program ==================

/*	Results:
Write a fraction in the form of x/y: 1/7
Write a fraction in the form of x/y: 7/8

The result of 1/7 * 7/8 is 7/56
*/