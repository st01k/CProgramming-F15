#include <stdio.h>
#include <stdlib.h>
// ...

int main (void)
{
//	Local Declarations 
FILE* spTemps;

//	Statements 
	// ...

	if ((spTemps = fopen("TEMPS.DAT", "r")) == NULL)
	   {
	    printf("\aERROR opening TEMPS.DAT\n");
	    exit (100);
	   } // if open 
	// ...

	if (fclose(spTemps) == EOF)
	   {
	    printf("\aERROR closing TEMPS.DAT\n");
	    exit (102);
	   } // if close 
	// ...

}	// main 

/*	Results:
ERROR opening TEMPS.DAT

Note: The close cannot be tested unless the file has been opened.
*/