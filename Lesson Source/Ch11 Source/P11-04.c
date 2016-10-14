/*	Demonstrate reading names from a file. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
//	Local Declarations
	char  first[80];
	char  last[80];
	int   score;
	FILE* spStuScores;
	
//	Statements
	if (!(spStuScores = fopen ("P11-04.TXT", "r")))
	   {
	    printf("\aCould not open student file.\n");
	    exit (100);
	   } // if
	
	// Read and print first name, last name, and score   
	while (fscanf(spStuScores, " %s %s %d",
	        first, last, &score) == 3)
	   printf("%s %s %3d\n", first, last, score);

	printf("End of Student List\n");
	fclose (spStuScores);
	return 0;
}	// main

/*	Results:
George Washington  95
Benedict Arnold  53
Mary Todd-Lincoln  91
End of Student List
*/