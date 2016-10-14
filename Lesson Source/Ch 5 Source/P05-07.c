/*	Test Driver to demonstrate switch statement.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations
	int printFlag = 8;
	
/*	Program fragment that demonstrates multiple
	cases for one set of statements
*/
switch (printFlag)
	{
	 case 1: 
	 case 3:  printf("Good Day\n"); 
	          printf("Odds have it!\n");
	          break;
	 case 2: 
	 case 4:  printf("Good Day\n");
	          printf("Evens have it!\n");
	          break;
	 default: printf("Good Day, I’m confused!\n");
	          printf("Bye!\n");
	          break;
	} // switch 
	return 0;
}	// main 

/*	Results
printFlag is 3:
	Good Day
	Odds have it!
printFlag is 2:
	Good Day
	Evens have it!
printFlag is 8
	Good Day, I’m confused!
	Bye!
*/