#include <stdio.h>
int main (void)
{
	int  i;
	int  j;
	int  sum;
	
	scanf("%d%d", &i, &j);
	sum = i + j;
	printf("The sum of %d & %d is %d\n", i, j, sum);
	return 0;
}	//  main 

/*	Results:
4 5
The sum of 4 & 5 is 9
*/