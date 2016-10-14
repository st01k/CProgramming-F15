/*	Test Driver for perpetual loops examples. Compile only.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdbool.h>

int main (void)
{
//	Local Declarations
	bool condition = true;
	int  x = 0;
	
//	Statements
	//	A bad for loop 
	for ( ; ; )
	   { 
	    // ...
	    if (condition)
	       break;
	   } // for 

	//	A better for loop 
	for ( ; !condition ; )
	   {
 	    // ...
 	   } // for 

	//	A bad while loop 
	while (x)
	   {
	    // ...
	    if (condition)
	        break;
	    else
	        // ...
	        ;
	   } // while 

	//	A better while loop 
	while  (x && !condition)
	   {
	    // ...
	    if (!condition)
	       // ... 
	       ;
	   } // while 

}	// main
