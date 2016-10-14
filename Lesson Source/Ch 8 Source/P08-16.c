/*	This program changes a two-dimensional array to the 
	corresponding one-dimensional array.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#define ROWS 2
#define COLS 5

int main (void)
{
//	Local Declarations
	int table [ROWS] [COLS] =
	   {
	    {00, 01, 02, 03, 04},
	    {10, 11, 12, 13, 14}
	   }; // table
	int line [ROWS * COLS];

//	Statements
	for (int row = 0; row < ROWS; row++)
	   for (int column = 0; column < COLS; column++)
	       line[row * COLS + column] = table[row][column]; 

	for (int row = 0; row < ROWS * COLS; row++)
	    printf(" %02d ", line[row]);

	return 0;
}	// main

/*	Results:
00  01  02  03  04  10  11  12  13  14 
*/