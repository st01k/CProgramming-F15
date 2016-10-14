/*	Test Driver for break flags. Compile only.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdbool.h>

int main (void)
{
//	Local Declarations
	bool breakFlag = true;
	int  x = 0;
	int  y = 0;
	int  z = 0;
	
//	Statements
	breakFlag = 0;
	while (!breakFlag)
	   {
        // ...
	    if (x && !y || z)            // Complex limit test
	       breakFlag = 1;
	    else
	       // ...
	       ;
   } // while
   return 0; 
}	// main

