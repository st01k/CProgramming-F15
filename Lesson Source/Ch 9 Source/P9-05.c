/*	This program shows how we can use different pointers 
	to point to the same data variable. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void) 
{
//	Local Declarations 
	int  a;
	int* p = &a; 
	int* q = &a; 
	int* r = &a; 

//	Statements 
	printf("Enter a number: ");
	scanf ("%d", &a); 
	printf("%d\n", *p); 
	printf("%d\n", *q); 
	printf("%d\n", *r); 

	return 0;
}	// main

/*	Results
Enter a number: 15

15 
15 
15 
*/