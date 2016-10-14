/*	Demonstrate the results of logical operators.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdbool.h>

int main (void)
{
//	Local Declarations 
	bool a = true;
	bool b = true;
	bool c = false;

//	Statements 
	printf("    %2d AND     %2d: %2d\n", a, b,  a &&  b);
	printf("    %2d AND     %2d: %2d\n", a, c,  a &&  c);
	printf("    %2d AND     %2d: %2d\n", c, a,  c &&  a);
	printf("    %2d OR      %2d: %2d\n", a, c,  a ||  c);
	printf("    %2d OR      %2d: %2d\n", c, a,  c ||  a);
	printf("    %2d OR      %2d: %2d\n", c, c,  c ||  c);
	printf("NOT %2d AND NOT %2d: %2d\n", a, c, !a && !c);
	printf("NOT %2d AND     %2d: %2d\n", a, c, !a &&  c);
	printf("    %2d AND NOT %2d: %2d\n", a, c,  a && !c);
	return 0;
}	// main 

/*	Results:
     1 AND      1:  1
     1 AND      0:  0
     0 AND      1:  0
     1 OR       0:  1
     0 OR       1:  1
     0 OR       0:  0
NOT  1 AND NOT  0:  0
NOT  1 AND      0:  0
     1 AND NOT  0:  1
*/