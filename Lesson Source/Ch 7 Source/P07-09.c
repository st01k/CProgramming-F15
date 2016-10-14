/*	This program counts characters and lines in a program.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void)
{
//	Local Declarations 
	int   curCh;
	int   preCh;
	int   countLn = 0;
	int   countCh = 0;
	FILE* sp1;

//	Statements 
	if (!(sp1 = fopen("P07-07.DAT", "r")))
	   {
	    printf("Error opening P07-07.DAT for reading");
	    return (1);
	   } // if open error 

	while ((curCh = fgetc(sp1)) != EOF)
	   {
	    if (curCh != '\n')
	        countCh++;
	    else
	        countLn++;
	    preCh = curCh;
	   } // while 

	if (preCh != '\n')
	    countLn++;

	printf("Number of characters: %d\n", countCh);
	printf("Number of lines     : %d\n", countLn);
	fclose(sp1);
 return 0;
}  // main

/*	Results:
Number of characters: 74
Number of lines     : 2

Input:
Now is the time for all good students
To come to the aid of their college.
*/