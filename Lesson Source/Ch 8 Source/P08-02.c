/*	Initialize array with square of index and print it.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#define ARY_SIZE 5

int main (void)
{
//	Local Declarations 
	int sqrAry[ARY_SIZE];

//	Statements 
	for (int i = 0; i < ARY_SIZE; i++) 
	   sqrAry[i] = i * i;

	printf("Element\tSquare\n");
	printf("=======\t======\n");
	for (int i = 0; i < ARY_SIZE; i++)
	   printf("%5d\t%4d\n", i, sqrAry[i]);
	return 0;
}	// main 

/*	Results:
Element Square
======= ======
    0      0
    1      1
    2      4
    3      9
    4     16
*/