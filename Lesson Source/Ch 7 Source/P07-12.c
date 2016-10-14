/*	Test driver for handling errors function
	   Written by:
	   Date"
*/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//	Function Declarations
int getUnitsSold (void);

//	Macros
#define FLUSH while (getchar() != '\n')

int main (void)
{
//	Statements
	getUnitsSold();
	printf("End of Test\n");
	return 0;
}	// main

/*	This function reads the units sold from the keyboard  
	and verifies the data with the user.
	   Pre   nothing
	   Post  units Sold read, verified, and returned
*/
int getUnitsSold (void)
{
//	Local Declarations
	int  unitsSold;
	bool valid;

//	Statements
do
	{
	 printf("\nPlease enter Number of Units Sold: ");
	 while (scanf("%d", &unitsSold) != 1)
	      {
	       FLUSH;
	       printf("\aInvalid number. Please re-enter: ");
	      }  // while 
	   printf("\nVerify Units Sold: %d: ", unitsSold);
	   printf("<Y> correct: <N> not correct: \n");
	   FLUSH;
	   if (toupper(getchar ()) == 'Y')
	       valid = true;
	   else
	      {
	       FLUSH;
	       printf("\nYou responded 'no.' ");
	       printf("Please re-enter Units Sold\n");
	       valid = false;
	       } // if 
	} while (!valid);
return unitsSold;
} // getUnitsSold 

/*	Results:

Please enter Number of Units Sold: 50

Verify Units Sold: 50: <Y> correct: <N> not correct: 
y
End of Test
*/