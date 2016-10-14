/*	This program prints the tuition at Strange College. 
	Strange charges $10 for registration, plus $10 per 
	unit and a penalty of $50 for each 12 units, or
	fraction of 12, over 12. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define REG_FEE    10
#define UNIT_FEE   10
#define EXCESS_FEE 50

//	Function Declarations 
int calculateFee (int firstTerm, int secondTerm,
                  int thirdTerm);
int termFee      (int units);

int main (void)
{
//	Local Declarations 
	int  firstTerm;
	int  secondTerm;
	int  thirdTerm;
	int  totalFee;

//	Statements 
	printf("Enter units for first term:  ");
	scanf ("%d", &firstTerm);

	printf("Enter units for second term: ");
	scanf ("%d", &secondTerm);

	printf("Enter units for third term:  ");
	scanf ("%d", &thirdTerm);

	totalFee = calculateFee 
	           (firstTerm, secondTerm, thirdTerm);
	printf("\nThe total tuition is : %8d\n", totalFee);

	return 0;
}	// main 

/* ================ calculateFee ================ 
	Calculate the total fees for the year.
	   Pre   The number of units to be taken each term.
	   Post  Returns the annual fees.
*/
int calculateFee (int firstTerm, int secondTerm,
                  int thirdTerm)
{
//	Local Declarations 
	int  fee;

//	Statements 
	fee = termFee   (firstTerm) 
	      + termFee (secondTerm)
	      + termFee (thirdTerm);
	return fee;
}	// calculateFee 

/* ==================== termFee ====================
	Calculate the tuition for one term 
	   Pre   units contains units for the term
	   Post  The fee is calculated and returned
*/
int termFee (int units)
{
//	Local Declarations 
	int  totalFees;

//	Statements 
	totalFees = REG_FEE
	            + ((units - 1)/12 * EXCESS_FEE)
	            + (units * UNIT_FEE);
	return (totalFees);
}	// termFee 

/*	Results:
Enter units for first term:  10
Enter units for second term: 20
Enter units for third term:  30

The total tuition is :      780 
*/