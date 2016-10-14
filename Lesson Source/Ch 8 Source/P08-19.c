/*	Read values from keyboard into a two-dimensional
	array. Create two one-dimensional arrays that 
	contain row and column averages.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLS 6

//	Function Declaration
void  getData       (int   table[][MAX_COLS]);

int main (void)
{
//	Local Declarations
	int   table     [MAX_ROWS][MAX_COLS];

	float rowAve    [MAX_ROWS] = {0};
	float columnAve [MAX_COLS] = {0};

//	Statements
	getData        (table);
	printf("\n**Tables built\n");

	for (int i = 0; i < MAX_ROWS; i++)
	    {
	     for (int y = 0; y < MAX_COLS; y++)
	          printf("%4d", table[i][y]);
	     printf("\n");
	    } // for i

	return 0;
}	// main

/*	===================== getData ====================
	Reads data and fills two-dimensional array.
	   Pre   table is empty array to be filled  
	   Post  array filled 
*/
void getData (int table[][MAX_COLS]) 
{
//	Statements
	for (int row = 0; row < MAX_ROWS; row++)
	   for (int col = 0; col < MAX_COLS; col++)
	       {
	        printf("\nEnter integer and <return>: ");
	        scanf("%d", &table[row][col]);
	       } // for col
	return;
} // getData
//	================ End of Program =================

/*	Results:
**Tables built
  10  12  14  16  18  20
  22  24  26  28  30  23
  25  27  29  31  33  35
  39  41  43  45  47  49
  51  53  55  57  59  61
*/