/*	Test driver for quadratic function.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <math.h>

//	Function Declarations 
void getData      (int*    pa,     int* pb, int* pc);
int  quadratic    (int     a,      int  b,  int  c, 
                   double* pRoot1, double* pRoot2); 
void printResults (int     numRoots, 
                   int     a,     int  b, int  c,
                   double  root1, double  root2); 

int main (void)
{
//	Local Declarations 
	int    a;
	int    b;
	int    c;
	int    numRoots;
	double root1;
	double root2;
	char   again = 'Y';

//	Statements 
	printf("Solve quadratic equations.\n\n");
	while (again == 'Y' || again == 'y')
	   {
	    getData (&a, &b, &c);
	    numRoots = quadratic (a, b, c, &root1, &root2);
	    printResults (numRoots, a, b, c, root1, root2);

	    printf("\nDo you have another equation (Y/N): ");
	    scanf (" %c", &again);
	   } // while
	printf("\nThank you.\n");
	return 0;
}	// main

/*	================== getData =================
	Read coefficients for quadratic equation.
	   Pre   a, b, and c contains addresses 
	   Post  data read into addresses in main 
*/
void getData   (int* pa, int* pb, int* pc)
{
//	Statements 
	printf("Please enter coefficients a, b, & c: ");
	scanf ("%d%d%d", pa, pb, pc);
	
	return;
}	// getData

/*	================== quadratic ================== 
	Compute the roots for a quadratic equation.
	   Pre    a, b, & c are the coefficients 
	          pRoot1 & pRoot2 are variable pointers 
	   Post   roots computed, stored in calling function
	   Return  2 two roots,
	           1 one root, 
	           0 imaginary roots
	          -1 not quadratic coefficients.
*/
int quadratic (int     a, int b, int c,
               double* pRoot1, double* pRoot2)
{
//	Local Declarations
	int result;
	
	double discriminant;
	double root;

//	Statements
	if (a == 0 && b == 0)
	   result = -1;
	else
	   if (a == 0)
	      {
	       *pRoot1 = -c / (double) b;
	       result = 1;
	      } // a == 0 
	   else
	      {
	       discriminant =  b * b  - (4 * a * c);
	       if (discriminant >= 0)
	          {
	           root    = sqrt(discriminant);
	           *pRoot1 = (-b + root) / (2 * a);
	           *pRoot2 = (-b - root) / (2 * a);
	           result  = 2;
	          } // if >= 0
	       else 
	           result = 0;
	      } // else
	return result;
}	// quadratic

/*	================= printResults ================ 
	Prints the factors for the quadratic equation.
	   Pre   numRoots contains 0, 1, 2 
	         a, b, c contains original coefficients 
	         root1 and root2 contains roots 
	   Post  roots have been printed 
*/ 
void printResults  (int    numRoots,
                    int    a,  int b,  int c,
                    double root1, double root2)
{
//	Statements
	printf("Your equation: %dx**2 + %dx + %d\n",
	        a, b, c);
	switch (numRoots) 
	   {
	    case 2:  printf("Roots are: %6.3f & %6.3f\n",
	                     root1, root2);
	             break;
	    case 1:  printf("Only one root: %6.3f\n",
	                     root1);
	             break;
	    case 0:  printf("Roots are imaginary.\n");
	             break;
	    default: printf("Invalid coefficients\n");
	             break;
	   } // switch
	return;
}	// printResults
//	================== End of Program =================

/*	Results:
Solve quadratic equations.

Please enter the coefficients a, b, & c: 2 4 2
Your equation: 2x**2 + 4x + 2
Roots are: -1.000 & -1.000

Do you have another equation (Y/N): y
Please enter the coefficients a, b, & c: 0 4 2
Your equation: 0x**2 + 4x + 2
Only one root: -0.500

Do you have another equation (Y/N): y
Please enter the coefficients a, b, & c: 2 2 2
Your equation: 2x**2 + 2x + 2
Roots are imaginary.

Do you have another equation (Y/N): y
Please enter the coefficients a, b, & c: 0 0 2
Your equation: 0x**2 + 0x + 2
Invalid coefficients

Do you have another equation (Y/N): y
Please enter coefficients a, b, & c: 1 -5 6
Your equation: 1x**2 + -5x + 6
Roots are:  3.000 &  2.000

Do you have another equation (Y/N): n

Thank you.
*/