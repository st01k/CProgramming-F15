/*	Given two Internet addresses, determine the number 
	of unique addresses in their range.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//	Local Declarations
	unsigned int   strt[4];
	unsigned int   end[4];
	unsigned long  add1 = 0;
	unsigned long  add2 = 0;
	unsigned long  range;

	char addr1[15];
	char addr2[15];

//	Statements
	printf ("Enter first address:  ");
	fgets (addr1 , sizeof (addr1) , stdin);

	printf ("Enter second address: ");
	fgets (addr2 , sizeof (addr2) , stdin);

	sscanf (addr1 , "%d %*c %d %*c %d %*c %d\n", 
	        &strt[3], &strt[2], &strt[1], &strt[0]);
	sscanf (addr2 , "%d %*c %d %*c %d %*c %d\n", 
	        &end[3], &end[2], &end[1], &end[0]);

	for (int i = 3 ; i >= 0  ; i--)
	    {
	      add1 = add1 * 256 + strt[i];
	      add2 = add2 * 256 + end[i];
	    } // for
	range = abs (add1 - add2) + 1;

	printf ("\nFirst Address: %s", addr1);
	printf ("Second Address %s", addr2);
	printf ("\nThe range: %ld\n", range);

	return 0;
}	// main

/*	Results:
Enter first address:  23.56.34.0
Enter second address: 23.56.32.255

First Address: 23.56.34.0
Second Address 23.56.32.255

The range: 258
*/