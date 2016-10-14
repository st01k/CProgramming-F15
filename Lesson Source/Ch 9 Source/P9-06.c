/*	Show how pointers to pointers can be used by different 
	scanf functions to read data to the same variable.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void) 
{
//	Local Declarations 
	int    a; 
	int*   p; 
	int**  q;
	int*** r;

//	Statements 
	p = &a; 
	q = &p; 
	r = &q;

	printf("Enter a number: ");
	scanf ("%d", &a);                        // Using a
	printf("The number is : %d\n", a);

	printf("\nEnter a number: ");
	scanf ("%d", p);                         // Using p
	printf("The number is : %d\n", a);

	printf("\nEnter a number: "); 
	scanf ("%d", *q);                        // Using q
	printf("The number is : %d\n", a); 

	printf("\nEnter a number: "); 
	scanf ("%d", **r);                       // Using r
	printf("The number is : %d\n", a); 

	return 0;
}	// main

/*	Results:
Enter a number: 1
The number is : 1

Enter a number: 2
The number is : 2

Enter a number: 3
The number is : 3

Enter a number: 4
The number is : 4
*/