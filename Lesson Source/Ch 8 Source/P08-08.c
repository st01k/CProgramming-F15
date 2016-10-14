/*	Generate a random number permutation.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>

#define  ARY_SIZE  20

//	Function Declarations 
void bldPerm   (int randNos[]);
void printData (int data[], int size, int lineSize);

int main (void)
{
//	Local Declarations 
	int randNos [ARY_SIZE];
	
//	Statements 
	printf("Begin Random Permutation Generation\n");
	
	bldPerm   (randNos);
	printData (randNos, ARY_SIZE, 10);
	
	return 0;
}	// main 

/*	==================== bldPerm ====================
	Generate a random number permutation in array.
	   Pre   randNos is array to receive permutations
	   Post  randNos filled
*/
void bldPerm (int randNos[])
{
//	Local Declarations
	int oneRandNo;
	int haveRand[ARY_SIZE] = {0};
	
//	Statements
	for (int i = 0; i < ARY_SIZE; i++)
	    {
	     do
	       {
	        oneRandNo = rand() % ARY_SIZE;
	       } while (haveRand[oneRandNo] == 1);
	     haveRand[oneRandNo] = 1;
	     randNos[i] = oneRandNo;
	    } // for
	return;
}	// bldPerm 

/*	==================== printData ====================
	Prints the data as a two-dimensional array.
	   Pre   data: a filled array
	         last: index to last element to be printed
	         lineSize: number of elements on a line
	   Post  data printed
*/
void printData (int data[], int size, int lineSize)
{
//	Local Declarations
	int numPrinted = 0;

//	Statements
	printf("\n");
	for (int i = 0; i < size; i++)
	   {
	    numPrinted++;
	    printf("%2d ", data[i]);
	    if (numPrinted >= lineSize)
	       {
	        printf("\n");
	        numPrinted = 0;
	       } // if 
	   } // for 
	printf("\n");
	return;
}	// printData

/*	Results:
Begin Random Permutation Generation

18 13 15 11  7 10 19 12  6  9 
 4  0  5  3 17 14  2 16  1  8 
*/