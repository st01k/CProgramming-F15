/*	Test driver for fill 2D array. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define MAX_ROWS  5
#define MAX_COLS  4

//	Prototype Declarations 
void fillArray (int table[][MAX_COLS], int numRows);

int main (void) 
{
//	Local Declarations 
	int row;
	int col;
	int	ary[MAX_ROWS][MAX_COLS]; 
	              
//	Statements 
	fillArray(ary, MAX_ROWS);
	printf("Data: \n");
	for (row = 0; row < 5; row++)
        {
         for (col = 0; col < 4; col++)
              printf("%8d", ary [row][col]);
         printf("\n");
        } // for  
	return 0;
}	// main 

/*	==================== fillArray ====================
	This function fills array such that each array element 
	contains a number that, when viewed as a two-digit 
	integer, the first digit is the row number and the 
	second digit is the column number.
	   Pre  table is array in memory
	        numRows is number of rows in array
	   Post array has been initialized
*/
void fillArray (int table[][MAX_COLS], int numRows) 
{
//	Statements
	for (int row = 0; row < numRows; row++)
	   {
	    table [row][0] = row * 10;
	    for (int col = 1; col < MAX_COLS; col++)
	        table [row][col] = table [row][col - 1] + 1;
	   } // for
	return;
}	// fillArray

/*	Results:
	Data:
	   0       1       2       3
      10      11      12      13
      20      21      22      23
      30      31      32      33
      40      41      42      43
*/
