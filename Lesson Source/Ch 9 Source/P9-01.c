/*	Demonstrate pointer use
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations
	int  a;
	int* p;

//	Statements
	a = 14;
	p = &a;

	printf("%d %p\n", a, &a);
	printf("%p %d %d\n", p, *p, a);

	return 0;
}	// main

/*	Results:
14 0xbffffd90
0xbffffd90 14 14
*/
