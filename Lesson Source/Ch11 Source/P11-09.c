/*	Write file double spaced.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//	Local Declarations
	char  strng[81]; 
	FILE* textIn;

//	Statements
	if (!(textIn = fopen("P11-07.TXT", "r")))
	   {
	    printf("\aCan’t open textdata\n");
	    exit (100);
	   } // if
	while (fgets(strng, sizeof(strng), textIn)) 
	   {
	    fputs(strng, stdout);
	    putchar ('\n'); 
	   } // while
	return 0;
}	// main

/*	Results:
Now is the time for all good students

To come to the aid of their college.

*/