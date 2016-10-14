/*	Copy a text file of integers.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//	Local Declarations 
	FILE* spIn;
	FILE* spOut;
	int   numIn;
	int   closeResult;
	
//	Statements 
	printf("Running file copy\n");
	spIn = fopen("P07-03.DAT", "r");
	if (!spIn)
	   {
	    printf("Could not open input file\a\n");
	    exit  (101);
	   } // if open fail 
	
	spOut = fopen("P07-04.DAT", "w");
	if (!spOut)
	   {
	    printf("Could not open output file\a\n");
	    exit  (102);
	   } // if open fail 

	while ((fscanf(spIn, "%d", &numIn)) == 1)
	   fprintf(spOut, "%d\n", numIn);
	
	closeResult = fclose(spOut);
	if (closeResult == EOF)
	   {
	    printf("Could not close output file\a\n");
	    exit  (201);
	   } // if close fail 
	
	printf("File copy complete\n");
	return 0;
}	// main 

/*	Results:
Running file copy
File copy complete

P07-04.DAT contains
1
2
3
4
5
6
7
8
9
10
*/