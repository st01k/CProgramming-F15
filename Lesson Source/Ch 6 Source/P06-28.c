/*	This program adds, subtracts, multiplies, and divides
	two integers.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

//	Function Declaration 
int   getOption (void);
void  getData   (int* a,      int* b);
float calc       (int option, int  num1, int num2);

float add  (float num1, float num2);
float sub  (float num1, float num2);
float mul  (float num1, float num2);
float divn (float num1, float num2);

void  printResult (float num1,   float num2,
                   float result, int   option);

int main (void)
{
//	Local Declarations 
	int    done = 0;
	int    option;
	float  num1;
	float  num2;
	float  result;

//	Statements 
	while (!done)
	  {
	   option = getOption();
	   if (option == 5)
	      done = 1;
	   else
	     {
	      do
	        {
	         printf("\n\nEnter two numbers: ");
	         scanf("%f %f", &num1, &num2);
	         if (option == 4 && num2 == 0)
	            {
	             printf("\a\n *** Error *** ");
	             printf("Second number cannot be 0\n"); 
	            } // if 
	        } while (option == 4 && num2 == 0);

	      switch (option)
	        {
	         case 1: result = add (num1, num2);
	                 break;
	         case 2: result = sub (num1, num2);
	                 break;
	         case 3: result = mul (num1, num2);
	                 break;
	         case 4: result = divn (num1, num2); 
	        } // switch 

	      printResult (num1, num2, result, option);
	     } // else option != 5 
	  } // while 
	printf("\nThank you for using Calculator.\n");
	return 0;
}	// main 

/*	==================== getOption ====================
	This function shows a menu and reads the user option.
	   Pre   nothing 
	   Post  returns a valid option 
*/
int getOption (void)
{ 
//	Local Declarations 
	int option;

//	Statements 
	do
	  {
	   printf("\n*******************");
	   printf("\n*       MENU      *");
	   printf("\n*                 *");
	   printf("\n*  1. ADD         *");
	   printf("\n*  2. SUBTRACT    *");
	   printf("\n*  3. MULTIPLY    *");
	   printf("\n*  4. DIVIDE      *");
	   printf("\n*  5. QUIT        *");
	   printf("\n*                 *");
	   printf("\n*******************");

	   printf("\n\n\nPlease type your choice ");
	   printf("and press the return key : ");
	   scanf("%d", &option);

	   if (option < 1 || option > 5)
	      printf("Invalid option. Please re-enter.\n");

	 } while (option < 1 || option > 5);
	return option;
}	// getOption 

/* ====================== getData ==================== 
	This function reads two integers from the keyboard.
	   Pre   Parameters a and b are addresses
	   Post  Data read into parameter addresses
*/
void getData (int* a, int* b)
{
	printf("Please enter two integer numbers: ");
	scanf("%d %d", a, b);
	return;
}	// getData 

/*	==================== calc ====================
	This function determines the type of operation
	and calls a function to perform it. 
	   Pre   option contains the operation
	         num1 & num2 contains data
	   Post  returns the results
*/
float calc (int option, int num1, int num2) 
{
// Local Declarations 
float result;

//	Statements 
	switch(option)
	    {
	     case 1:  result = add (num1, num2);
	              break;
	     case 2:  result = sub (num1, num2);
	              break;
	     case 3:  result = 3.0;              // Multiply
	              break;
	     case 4:  if (num2 == 0.0)           // Divide
	                 {
	                  printf("\n\a\aError: ");
	                  printf("division by zero ***\n");
	                  exit (100);
	                 } // if 
	              else
	                  result = 4.0;
	              break;
	     /* Better structured programming would validate the
	        option in getOption. However, we have not  
	        yet learned the technique to code it there.
	     */
	     default: printf("\aOption not available\n");
	              exit (101);
		} // switch 
printf("**In calc result is: %6.2f\n", result);
	return result;
}	// calc 

/* ====================== add ====================== 
	This function adds two numbers and returns the sum.
	   Pre   a and b contain values to be added
	   Post  Returns a + b
*/
float add (float a, float b)
{
//	Local Definitions
	float sum;

//	Statements
	sum = a + b;
	return sum;
}	// add 

/* ====================== sub ====================== 
	This function subtracts two numbers
	   Pre   a and b contain values to be subtracted
	   Post  Returns a + b
*/
float sub (float a, float b)
{
//	Local Definitions
	float dif;

//	Statements
	dif = a - b;
printf("**In sub result is:  %6.2f\n", dif);
	return dif;
}	// sub 

/*	====================== mul ======================
	This function multiplies two numbers.
	   Pre   The two numbers are given as parameters
	   Post  returns the results
*/
float mul (float num1,
           float num2)
{
/*	Local Definitions */
	float res;

/*	Statements */
	res = num1 * num2;
	return res;
}	/* mul */
/*	====================== divn ======================
	This function divides two numbers.
	   Pre   The two numbers are given as parameters
	   Post  returns the results
*/
float divn (float num1, float num2)
{
//	Local Definitions 
	float res;

//	Statements 
	res = num1 / num2;
	return res;
}	// divn 
/*	=================== printResult ===================
	This function prints the result of calculation.
	   Pre   The two numbers, result, and option are given
	   Post  Prints the numbers and the result
*/
void printResult (float num1, float num2,
                  float res,  int   option)
{
//	Statements 
	printf("\n%8.2f ", num1);
	switch (option)
	   {
	    case 1: printf(" + ");
	            break;
	    case 2: printf(" - ");
	            break;
	    case 3: printf(" * ");
	            break;
	    case 4: printf(" / ");
	            break;
	   } // switch option 
	printf(" %.2f = %.2f\n", num2, res);

	return;
}	// printResults 
//	================== End of Program ================== 

/*	Results: 

*******************
*       MENU      *
*                 *
*  1. ADD         *
*  2. SUBTRACT    *
*  3. MULTIPLY    *
*  4. DIVIDE      *
*  5. QUIT        *
*                 *
*******************


Please type your choice and press the return key : 1


Enter two numbers: 10 3

   10.00  +  3.00 = 13.00

*******************
*       MENU      *
*                 *
*  1. ADD         *
*  2. SUBTRACT    *
*  3. MULTIPLY    *
*  4. DIVIDE      *
*  5. QUIT        *
*                 *
*******************


Please type your choice and press the return key : 2


Enter two numbers: 10 3
**In sub result is:    7.00

   10.00  -  3.00 = 7.00

*******************
*       MENU      *
*                 *
*  1. ADD         *
*  2. SUBTRACT    *
*  3. MULTIPLY    *
*  4. DIVIDE      *
*  5. QUIT        *
*                 *
*******************


Please type your choice and press the return key : 3


Enter two numbers: 10 3

   10.00  *  3.00 = 30.00

*******************
*       MENU      *
*                 *
*  1. ADD         *
*  2. SUBTRACT    *
*  3. MULTIPLY    *
*  4. DIVIDE      *
*  5. QUIT        *
*                 *
*******************


Please type your choice and press the return key : 4


Enter two numbers: 10 0

 *** Error *** Second number cannot be 0


Enter two numbers: 10 3

   10.00  /  3.00 = 3.33

*******************
*       MENU      *
*                 *
*  1. ADD         *
*  2. SUBTRACT    *
*  3. MULTIPLY    *
*  4. DIVIDE      *
*  5. QUIT        *
*                 *
*******************


Please type your choice and press the return key : 5

Thank you for using Calculator.
*/