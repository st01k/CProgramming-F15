/*	Nested if in two-way selection.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations
	int a;
	int b;

//	Statements 
	printf("Please enter two integers: ");
	scanf ("%d%d", &a, &b);

	if (a <= b) 
	   if (a < b)
	      printf("%d < %d\n", a, b);
	   else
	      printf("%d == %d\n", a, b);
	else
	   printf("%d > %d\n", a, b);

	return 0;
}	// main 

/*	Results:
Please enter two integers: 10 10
10 == 10
*/