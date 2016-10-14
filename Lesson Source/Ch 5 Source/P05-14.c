/*	Test Driver for good & poor coding styles
	   Written by:
	   Date: 
*/

#include <stdio.h>
#include <ctype.h>

//	Function Declarations
int someFunPoor (int a, int b);
int someFunGood (int a, int b);

int main (void)
{
//	Statements 
	printf("Poor Style: result is %d\n", 
	        someFunPoor (3, 8));
	printf("Good Style: result is %d\n", 
	        someFunGood (3, 8));
	return 0;
}	// main 

//	Poor Style
int someFunPoor (int a, int b)
{
int x;

	if (a < b)
	x = a;
	else
	   x = b;
	   x *= .5f;
	return x;
}	// someFun

//	Good Style
int someFunGood (int a, int b)
{
	int x;

	if (a < b)
	   x = a;
	else
	   x = b;
	x *= .5f;
	return x;
}	// someFun 


/*	Results:
Poor Style: result is 1
Good Style: result is 1
*/