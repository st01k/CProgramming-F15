/*	Copy a text file of integers.
	   Written by:
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//	Local Declarations 
	FILE* spAppnd;
	int   numIn;
	int   closeResult;
	
//	Statements 
	printf("This program appends data to a file\n");
	spAppnd = fopen("P07-05.DAT", "a");
	if (!spAppnd)
	   {
	    printf("Could not open input file\a\n");
	    exit  (101);
	   } // if open fail 
	
	printf("Please enter first number:  ");
	while ((scanf("%d", &numIn)) != EOF)
	   {
	    fprintf(spAppnd, "%d\n", numIn);
	    printf("Enter next number or <EOF>: ");
	   } // while 
	
	closeResult = fclose(spAppnd);
	if (closeResult == EOF)
	   {
	    printf("Could not close output file\a\n");
	    exit  (201);
	   } // if close fail 
	
	printf("\nFile append complete\n");
	return 0;
}	// main 

/*	Results:
First Run:
	This program appends data to a file
	Please enter first number:  1
	Enter next number or <EOF>: 2
	Enter next number or <EOF>: 3
	Enter next number or <EOF>:^d
	File append complete

Second Run:
	This program appends data to a file
	Please enter first number:  11
	Enter next number or <EOF>: 12
	Enter next number or <EOF>: 13
	Enter next number or <EOF>: 14
	Enter next number or <EOF>: 15
	Enter next number or <EOF>: 
	File append complete

File after second run:
1
2
3
11
12
13
14
15
*/