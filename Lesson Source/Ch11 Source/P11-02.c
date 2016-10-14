/*	Read only second integer. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//	Local Declarations
	int   amount;
	FILE* spData;

//	Statements
	if (!(spData = fopen ("P11-03.TXT", "r")))
	   {
	    printf("\aCould not open input file.\n");
	    exit (100);
	   } // if
	// Read and print only second integer 
	while (fscanf(spData, 
	      " %*d%d%*[^\n]", &amount) != EOF)
	    printf("Second integer: %4d\n", amount);

	printf("End of program\n");
	fclose (spData);
	return 0;
}	// main

/*	Input:
123 456 7.89
987 654 3.21

Results:
Second integer: 456
Second integer: 654
End of program
*/