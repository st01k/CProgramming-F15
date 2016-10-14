/*	This program uses a menu to allow the user to add, 
	multiply, subtract, or divide two integers. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>

//	Function Declarations 
int   getOption   (void);

int main (void)
{
//	Local Declarations 
	int   option;

//	Statements 
	option = getOption();

	printf("You selected option %d\n", option);
	
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
printf("You selected option %d\n", option);
	return option;
}	// getOption 

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

Please type your choice and key return: 3
You selected option 3
You selected option 3
*/