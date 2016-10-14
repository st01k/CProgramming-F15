/*	Demonstrates an array of pointers to strings.
	   Written by: 
	   Date written: 
*/
#include <stdio.h> 

int main (void)
{
//	Local Declarations
	char*  pDays[7];
	char** pLast;
	
//	Statements
	pDays[0] = "Sunday";
	pDays[1] = "Monday";
	pDays[2] = "Tuesday";
	pDays[3] = "Wednesday";
	pDays[4] = "Thursday";
	pDays[5] = "Friday";
	pDays[6] = "Saturday";

	printf("The days of the week\n");
	pLast = pDays + 6;
	for (char** pWalker = pDays;
	            pWalker <= pLast;
	            pWalker++)
	     printf("%s\n", *pWalker);
	return 0;
} // main

/*	Results:
The days of the week
Sunday
Monday
Tuesday
Wednesday
Thursday
Friday
Saturday
*/