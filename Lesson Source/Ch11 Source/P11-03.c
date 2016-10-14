/*	Delete leading spaces at beginning of line.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <ctype.h>

int main (void)
{
//	Local Declarations
	char line[80];

//	Statements
	printf("Enter data:  ");
	while ((fscanf(stdin, "%*[\t\v\f ]%79[^\n]", line))
	                      != EOF)
	   {
	    printf("You entered: %s\n", line);
	    
	    // Discard newline and set line to null string
	    fgetc (stdin);
	    *(line) = '\0';
	    printf("Enter data:  ");
	   } // while
	
	printf("\nThank you\n");
	return 0;
}	// main

/*	Results:
Enter data:  No whitespace here.
You entered: No whitespace here.
Enter data:   Only one whitespace character.
You entered: Only one whitespace character.
Enter data:        Tabs and spaces here.
You entered: Tabs and spaces here.
Enter data:  Next line is only one space.
You entered: Next line is only one space.
Enter data:   
You entered:  
Enter data:  ^d
Thank you
*/