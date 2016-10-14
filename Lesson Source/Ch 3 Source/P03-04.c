/*	Demonstrate examples of compound assignments.
	   Written by:
	   Date:
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations 
	int x;
	int y;

//	Statements 
	x = 10;
	y = 5;

	printf("x: %2d  |  y: %2d ",    x, y);
	printf("  |  x *= y + 2: %2d ", x *= y + 2);
	printf("  |  x is now: %2d\n",  x);

	x = 10;
	printf("x: %2d  |  y: %2d ",    x, y);
	printf("  |  x /= y + 1: %2d ", x /= y + 1);
	printf("  |  x is now: %2d\n",  x);

	x = 10;
	printf("x: %2d  |  y: %2d ",     x, y);
	printf("  |  x %%= y - 3: %2d ", x %= y - 3);
	printf("  |  x is now: %2d\n", x);

	return 0;
}	// main 
/*	x: 10  |  y:  5   |  x %= y - 3:  0   |  x is now:  0
Results:
x: 10  |  y:  5   |  x *= y + 2: 70   |  x is now: 70
x: 10  |  y:  5   |  x /= y + 1:  1   |  x is now:  1
x: 10  |  y:  5   |  x %= y - 3:  0   |  x is now:  0
*/