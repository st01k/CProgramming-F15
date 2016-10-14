/*	This program shows how the same pointer can point to 
	different data variables in different statements. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void) 
{
//	Local Declarations 
	int  a;
	int  b;
	int  c;
	int* p;

//	Statements 
	printf("Enter three numbers and key return: "); 
	scanf ("%d %d %d", &a, &b, &c); 
	p = &a; 
	printf("%3d\n", *p);
	p = &b;
	printf("%3d\n", *p); 
	p = &c; 
	printf("%3d\n", *p); 
	return 0;
}	// main

/*	Results
Enter three numbers and key return: 10 20 30

 10 
 20 
 30 
*/