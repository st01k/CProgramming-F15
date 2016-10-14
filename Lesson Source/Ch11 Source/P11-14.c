/*	Parse a simple algebraic expression.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <string.h>

int main (void)
{
//	Local Declarations
	char* strng = "sum = sum + 10;";
	char* pToken;
	int   tokenCount;

//	Statements
	tokenCount = 0;
	pToken = strtok (strng, " ;");

	while (pToken)
	   {
	    tokenCount++;
	    printf("Token %2d contains %s\n", 
	            tokenCount, pToken);
	    pToken = strtok (NULL, " ;");
	   } // while

	printf("\nEnd of tokens\n");
	return 0;
}	// main

/*	Results:
Token  1 contains sum 
Token  2 contains = 
Token  3 contains sum 
Token  4 contains + 
Token  5 contains 10 

End of tokens
*/