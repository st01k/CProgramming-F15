/*	Test driver for function to print a calendar month.
	   Written by:
	   Date: 
*/
#include <stdio.h>

//	Prototype Declarations 
void printMonth (int startDay, int days);

int main (void)
{
//	Statements 
	printMonth (2, 29);             // Day 2 is Tuesday
	return 0;
}	// main 

/*	================= printMonth =================
	Print one calendar month.
	   Pre   startDay is day of week relative 
	            to Sunday (0)
	         days is number of days in month
	   Post  Calendar printed
*/
void printMonth (int startDay, int days)
{
//	Local Declarations 
	int weekDay;

//	Statements 
	// print day header 
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	printf("--- --- --- --- --- --- ---\n");
	
	// position first day 
	for (weekDay = 0; weekDay < startDay; weekDay++)
	    printf("    ");
	    
	for (int dayCount = 1; dayCount <= days; dayCount++)
	    {
	     if (weekDay > 6)
	        {
	         printf("\n");
	         weekDay = 1;
	        } // if 
	     else
	         weekDay++;
	     printf("%3d ", dayCount);
	    } // for 
	printf("\n--- --- --- --- --- --- ---\n");
	return;
}	// printMonth 

/*	Results:
Sun Mon Tue Wed Thu Fri Sat
--- --- --- --- --- --- ---
          1   2   3   4   5 
  6   7   8   9  10  11  12 
 13  14  15  16  17  18  19 
 20  21  22  23  24  25  26 
 27  28  29 
--- --- --- --- --- --- ---
*/