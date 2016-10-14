/*	Demonstrate fput string
	   Written by: 
	   Date: 
*/
#include <stdio.h> 

int main (void) 
{
//	Local Definitions
	char str[] = "Necessity Is the Mother of Invention.";
	char* pStr = str; 

//	Statements 
	fputs(pStr, stdout);
	fputs("\n", stdout); 
	fputs(pStr + 13, stdout); 
	return 0; 
}	// main 

/*	Results:
Necessity Is the Mother of Invention
the Mother of Invention.
*/