/*
************************************************************
*                  Char, Int, and Float                    *
*               Chapter 2, Assignment 1.2                  *
*                 Author: Casey Murphy                     *
*                Date Created: 27 Aug 15                   *
*               Last Modified: 28 Aug 15                   *
*                                                          *
*  Reads a character, integer, and a floating point number *
*  then prints them using proper format specifications.    *
************************************************************
*/

#include <stdio.h>

int main (void)
{
/* local declarations */
    char userChar;
    int userInt;
    float userFloat;

/* statements */
    printf("Enter any single ASCII character, then press enter: ");
    scanf("%c", &userChar);
    printf("\nEnter an integer (+ or - 2,147,483,647), then press enter: ");
    scanf("%d", &userInt);
    printf("\nEnter a floating point value with < 7 decimal places, then press enter: ");
    scanf("%f", &userFloat);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    printf("You entered the character: %c.\n", userChar);
    printf("It's ASCII code is: %d\n\n", userChar);
    printf("You entered the integer: %d\n", userInt);
    printf("You entered the floating point value: %f\n", userFloat);
    return 0;
} /* main */
