/*	Test Driver for Checking scanf Results
	   Written by:
	   Date:
*/
#include <stdio.h>

#define FLUSH while (getchar() != '\n')
#define ERR1 "\aPrice incorrect. Re-enter both fields\n" 
#define ERR2 "\aAmount incorrect. Re-enter both fields\n" 

int main (void)
{
//	Local Declarations
	int   ioResult;
	int   amount;
	float price;

//	Statements
		
	// Read price and amount 
	 do
	   {
	    printf("\nEnter amount and price: ");
	    ioResult = scanf("%d%f", &amount, &price);

	    if (ioResult != 2)
	       {
	        FLUSH;
	        if (ioResult == 1)
	            printf(ERR1);
	        else
	            printf(ERR2);
	       } // if 
	   } while (ioResult != 2);

	return 0;
}	// main

/*	Results:
Enter amount and price: ? 15.25
Amount incorrect. Re-enter both fields

Enter amount and price: 100 ?
Price incorrect. Re-enter both fields

Enter amount and price: 100 15.25
*/