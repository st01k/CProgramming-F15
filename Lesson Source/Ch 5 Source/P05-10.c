/*	This program demonstrates the use of the character 
	classification functions found in the c-type library. 
	Given a character, it displays the highest 
	classification for the character.
	   Written by:
	   Date: 
*/

#include <stdio.h>
#include <ctype.h>

int main (void)
{
//	Local Declarations 
	char charIn;
	
//	Statements 
	printf("Enter a character to be examined: ");
	scanf ("%c", &charIn);
	
	if (islower(charIn))
	    printf("You entered a lowercase letter.\n");
	else if (isupper(charIn))
	    printf("You entered an uppercase character.\n");
	else if (isdigit(charIn))
	    printf("You entered a digit.\n");
	else if (ispunct(charIn))
	    printf("You entered a punctuation character.\n");
	else if (isspace(charIn))
	    printf("You entered a whitespace character.\n");
	else
	    printf("You entered a control character\n");
	return 0;
}	// main 

/*	Results:
First Run
	Enter a character to be examined: a
	You entered a lowercase letter.
Second Run
	Enter a character to be examined: ~
	You entered a punctuation character.
*/