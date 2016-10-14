/*	Print report showing value of investment.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations 
	double presVal;
	double futureVal;
	double rate;
	int    years;
	int    looper;

//	Statements 
	printf("Enter value of investment:   ");
	scanf ("%lf", &presVal);
	printf("Enter rate of return (nn.n): ");
	scanf ("%lf", &rate);
	printf("Enter number of years:       ");
	scanf ("%d", &years);

	printf("\nYear    Value\n");
	printf("====  ========\n");
	for (futureVal = presVal, looper = 1;
	     looper <= years;
	     looper++)
	    {
	     futureVal = futureVal * (1 + rate/100.0);
	     printf("%3d%11.2lf\n", looper, futureVal);
	    } // for 
	return 0;
}	// main 

/*	Results:
Enter value of investment:   10000
Enter rate of return (nn.n): 7.2
Enter number of years:       5

Year      Value
====    ========
  1     10720.00
  2     11491.84
  3     12319.25
  4     13206.24
  5     14157.09
*/