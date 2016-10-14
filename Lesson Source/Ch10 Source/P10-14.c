/*	This program tests the reusability of dynamic memory.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//	Local Declarations
	int  looper;
	int* ptr;
	
//	Statements
	for (looper = 0; looper < 5; looper++)
	   {
	    ptr = malloc(16);
	    printf("Memory allocated at: %p\n", ptr);
 
	    free (ptr);
	   } // for
	return 0;
}	// main

/*	Results in Personal Computer:
	Memory allocated at: 0x00e7fc32
	Memory allocated at: 0x00e8024a
	Memory allocated at: 0x00e8025c
	Memory allocated at: 0x00e8026e
	Memory allocated at: 0x00380280

	Results in UNIX system: 
	Memory allocated at: 0x00300f70
	Memory allocated at: 0x00300f70
	Memory allocated at: 0x00300f70
	Memory allocated at: 0x00300f70
	Memory allocated at: 0x00300f70
*/