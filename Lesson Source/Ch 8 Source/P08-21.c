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
void getData      (int   table[][MAX_COLS]); 
void rowAverage   (int   table[][MAX_COLS],
                   float rowAvrg []);
void colAverage   (int   table[][MAX_COLS],
                   float colAvrg []);
void  printTables (int   table[][MAX_COLS], 
                   float rowAvrg[], 
                   float colAvrg[]);

int main (void)
{
//	Local Declarations
	int   table  [MAX_ROWS][MAX_COLS];

	float rowAve [MAX_ROWS] = {0};
	float colAve [MAX_COLS] = {0};

//	Statements
	getData (table);
	rowAverage (table, rowAve);
//	colAverage (table, colAve);

	printf("\n");
	printTables (table, rowAve, colAve);
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

/* =================== rowAverage ===================
	This function calculates the row averages for a table
	   Pre   table has been filled with values
	   Post  averages calculated and in average array
*/
void rowAverage (int    table[][MAX_COLS],
                 float  rowAvrg [])
{
// Statements
	for (int row = 0; row < MAX_ROWS; row++)
	    {
	     for (int col = 0; col < MAX_COLS; col++)
	         rowAvrg[row] += table [row][col];
	     rowAvrg [row] /=  MAX_COLS;
	    } // for row
	return;
}	// rowAverage

/*	=================== printTables ===================
	Print data table, with row average at end of each 
	row and average of columns below each column.
	   Pre   each table filled with its data
	   Post  tables printed
*/
void printTables (int    table[][MAX_COLS],
                  float  rowAvrg[], 
                  float  colAvrg[])
{
//	Statements
	for (int row = 0; row < MAX_ROWS; row++)
	   {
	    for (int col = 0; col < MAX_COLS; col++)
	         printf("%6d", table[row][col]);
	    printf("   | %6.2f\n", rowAvrg [row]);
	   } // for row

	printf("---------------------------------------\n");
	printf("   ");
	for (int col = 0; col < MAX_COLS; col++)
	     printf("%6.2f", colAvrg[col]);
	return;
}	// printTables
//	================ End of Program =================

/*	Results:
    10    12    14    16    18    20   |  15.00
    22    24    26    28    30    23   |  25.50
    25    27    29    31    33    35   |  30.00
    39    41    43    45    47    49   |  44.00
    51    53    55    57    59    61   |  56.00
---------------------------------------
     0.00  0.00  0.00  0.00  0.00  0.00
*/