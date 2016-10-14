/*	Typewriter program: adds two spaces to the left 
	margin and writes line to file
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
//	Local Declarations
	FILE* spOutFile;
	char  strng[81];

//	Statements
	if (!(spOutFile = fopen("P11-11.TXT", "w")))
	   {
	    printf("\aCould not open output file.\n");
	    exit (100);
	   } // if

	while (fgets(strng, sizeof(strng), stdin))
	   {
	    fputc(' ', spOutFile); 
	    fputc(' ', spOutFile); 
	    fputs(strng, spOutFile); 
	    if (strng[strlen(strng) - 1] != '\n')
	        fputs("\n", spOutFile);
	   } // while
	fclose (spOutFile);
	return 0;
}	// main

/*	Results:
	Now is the time
	for all good students
	to come to the aid
	of their school.^d

	P11-11.TXT contains:
	  Now is the time
	  for all good students
	  to come to the aid
	  of their school.
*/