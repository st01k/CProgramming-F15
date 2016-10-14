/*	Read a text file of integers, and print the contents.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//	Local Declarations 
	FILE* spIn;
	int   numIn;
	
//	Statements 
	spIn = fopen("P07-03.DAT", "r");
	if (!spIn)
	   {
	    printf("Could not open file\a\n");
	    exit  (101);
	   } // if open fail 
	
	while ((fscanf(spIn, "%d", &numIn)) == 1)
	   printf("%d ", numIn);
	   
	return 0;
}	// main 


/*	Results:
1 2 3 4 5 6 7 8 9 10 
*/