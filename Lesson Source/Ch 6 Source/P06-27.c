/*	Test driver for Towers of Hanoi
	   Written by:
	   Date: 
*/
#include <stdio.h>

/*	Prototype Declarations */
void towers (int n, char source, char dest, char auxiliary);

int main (void)
{
/*	Local Definitions */
	int numDisks;
	
/*	Statements */
	printf("Please enter number of disks: ");
	scanf ("%d", &numDisks);
	
	printf("Start Towers of Hanoi.\n\n");

	towers (numDisks, 'A', 'C', 'B');
	
	printf("\nI Hope you didn't select 64 and end the world!\n");
	
	return 0;
}	/* main */

/*	Move one disk from source to destination through 
	the use of recursion.
	   Pre   The tower consists of n disks--source,
	         destination, & auxiliary towers given
	   Post  Steps for moves printed 
*/
void towers (int   n,
             char  source,
             char  dest,
             char  auxiliary)
{
/*	Local Definitions */
	static int step = 0;

/*	Statements */
	printf("Towers (%d, %c, %c, %c)\n",
	                 n, source, dest, auxiliary);
	if (n == 1)
	    printf("\t\t\t\tStep %3d: Move from %c to %c\n", 
	           ++step, source, dest);
	else
	   {
	    towers (n - 1, source, auxiliary, dest);
	    printf("\t\t\t\tStep %3d: Move from %c to %c\n", 
	           ++step, source, dest);
	    towers (n - 1, auxiliary, dest, source);
	   } /* if … else */
	return;
}	/* towers */ 

/*	Results:
Please enter number of disks: 3
Start Towers of Hanoi.

Towers (3, A, C, B)
Towers (2, A, B, C)
Towers (1, A, C, B)
                Step   1: Move from A to C
                Step   2: Move from A to B
Towers (1, C, B, A)
                Step   3: Move from C to B
                Step   4: Move from A to C
Towers (2, B, C, A)
Towers (1, B, A, C)
                Step   5: Move from B to A
                Step   6: Move from B to C
Towers (1, A, C, B)
                Step   7: Move from A to C

I Hope you didn't select 64 and end the world!
*/
