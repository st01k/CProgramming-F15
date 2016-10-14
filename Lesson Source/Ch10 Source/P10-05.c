/*	Demonstrate storing arrays in the heap. This program
	builds and manipulates a variable number of ragged 
	arrays. It then calculates the minimum, maximum, and 
	average of the numbers in the arrays.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//	Function Declarations
int** buildTable   (void);
void  fillTable    (int** table); 
void  processTable (int** table); 
int   smaller      (int   first, int second);
int   larger       (int   first, int second);
int   rowMinimum   (int*  rowPtr);
int   rowMaximum   (int*  rowPtr);
float rowAverage   (int*  rowPtr);

//	Include functions
#include "P10-06.c"
#include "P10-07.c"
#include "P10-08.c"
#include "P10-09.c"
#include "P10-10.c"
#include "P10-11.c"
#include "P10-12.c"
#include "P10-13.c"


int main (void)
{
//	Local Declarations
   int** table;

//	Statements
	table = buildTable(); 
	fillTable    (table); 
	processTable (table); 
	return 0; 
}	// main

/*	Results

Enter the number of rows in the table: 3
Enter number of integers in row 1: 3
Enter number of integers in row 2: 4
Enter number of integers in row 3: 2

 =============================
 Now we fill the table.

 For each row enter the data
 and press return: 
 =============================

 row 1 (3 integers) =====> 11 12 13

 row 2 (4 integers) =====> 24 23 22 21

 row 3 (2 integers) =====> 34 35

The statistics for row 1 
The minimum:    11
The maximum:    13
The average:    12.00 
The statistics for row 2 
The minimum:    21
The maximum:    24
The average:    22.50 
The statistics for row 3 
The minimum:    34
The maximum:    35
The average:    34.50 
*/