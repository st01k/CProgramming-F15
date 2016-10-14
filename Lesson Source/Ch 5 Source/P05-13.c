/*	This program uses a menu to allow the user to add, 
	multiply, subtract, or divide two integers. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

//	Function Declarations 
int   getOption (void);
void  getData   (int* num1, int* num2);
float calc      (int option, int num1, int num2);
float add       (int num1,   int num2);
float sub       (int num1,   int num2);

int main (void)
{
//	Local Declarations 
	int   option;
	int   num1;
	int   num2;
	float result;

//	Statements 
	option = getOption();
	getData (&num1, &num2);
	result = calc (option, num1, num2);
printf("**In main result is: %6.2f\n", result);
	
	return 0;
}	// main 

/*	==================== getOption ==================== 
	This function shows a menu and reads the user option.
	   Pre    Nothing
	   Post   returns the option
*/
int getOption (void)
{
//	Local Declarations 
	int option;

//	Statements 
	printf  ("\t**********************************");
	printf("\n\t*              MENU              *");
	printf("\n\t*                                *");
	printf("\n\t*  1. ADD                        *");
	printf("\n\t*  2. SUBTRACT                   *");
	printf("\n\t*  3. MULTIPLY                   *");
	printf("\n\t*  4. DIVIDE                     *");
	printf("\n\t*                                *");
	printf("\n\t**********************************");

	printf("\n\nPlease type your choice ");
	printf("and key return: ");
	scanf ("%d", &option);
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
	     /* Better structured programming would validate
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
float add (int a, int b)
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
float sub (int a, int b)
{
//	Local Definitions
	float dif;

//	Statements
	dif = a - b;
printf("**In sub result is:  %6.2f\n", dif);
	return dif;
}	// sub 

/*	Results: 
    **********************************
    *              MENU              *
    *                                *
    *  1. ADD                        *
    *  2. SUBTRACT                   *
    *  3. MULTIPLY                   *
    *  4. DIVIDE                     *
    *                                *
    **********************************

Please type your choice and key return: 2
Please enter two integer numbers: 13 8
**In sub result is:    5.00
**In calc result is:   5.00
**In main result is:   5.00
*/