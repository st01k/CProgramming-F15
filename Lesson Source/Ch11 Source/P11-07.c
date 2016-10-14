/*	This program creates a text file from the keyboard.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
//	Local Declarations
	char  str[100];
	FILE* spOut;
	
//	Statements
	if (!(spOut = fopen ("P11-07.TXT", "w")))
	   {
	    printf("\aCould not open output file.\n");
	    exit (100);
	   } // if
	while (fgets(str, sizeof (str), stdin))
	   fputs(str,  spOut); 
	fclose (spOut);
	return 0;
}	// main

/*	Results (file contents):
Now is the time for all good students
To come to the aid of their college.
*/