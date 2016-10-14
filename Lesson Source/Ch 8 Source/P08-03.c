/*	Read a number series and print it reversed.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations 
	int readNum;
	int numbers[50];

//	Statements 
	printf("You may enter up to 50 integers:\n");
	printf("How many would you like to enter? ");
	scanf ("%d", &readNum);
	
	if (readNum > 50)
	    readNum = 50;
	
	// Fill the array 
	printf("\nEnter your numbers: \n");
	for (int i = 0; i < readNum; i++)
	     scanf("%d", &numbers[i]);
	     
	// Print the array 
	printf("\nYour numbers reversed are: \n");
	for (int i = readNum - 1, numPrinted = 0; 
	         i >= 0;
	         i--)
	   {
	    printf("%3d", numbers[i]);
	    if (numPrinted < 9)
	        numPrinted++;
	    else
	       {
	        printf("\n");
	        numPrinted = 0;
	       } // else 
	   } // for 
	return 0;
}	// main 

/*	Results:
You may enter up to 50 integers:
How many would you like to enter? 12

Enter your numbers: 
1 2 3 4 5 6 7 8 9 10 11 12

Your numbers reversed are: 
 12 11 10  9  8  7  6  5  4  3
  2  1
*/