/*	Echo keyboard input that begins with capital letter.
	   Written by: 
	   Date written: 
*/
#include <ctype.h>
#include <stdio.h>

int main (void)
{
//	Local Declarations
	char strng[81]; 

//	Statements 
	while (fgets (strng, sizeof(strng), stdin)) 
	    if (isupper(*strng))
	        fputs(strng, stdout);
	return 0;
}	// main

/*	Results:
Now is the time
Now is the time
for all good students
to come to the aid
of their school.
Amen
Amen
^d
*/