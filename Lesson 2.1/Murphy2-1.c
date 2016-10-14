/*
************************************************************
*                  Fun with Constants                      *
*               Chapter 2, Assignment 1.1                  *
*                 Author: Casey Murphy                     *
*                Date Created: 27 Aug 15                   *
*               Last Modified: 31 Aug 15                   *
*                                                          *
*   Prints various characters and integers using defined   *
*   constants, memory constants, and literal constants.    *
************************************************************
*/

#include <stdio.h>

/* vowel defined constants */
#define A 'a'
#define E 'e'
#define I 'i'
#define O 'o'
#define U 'u'

int main (void)
{
/* local declarations */
/* even numbers as memory constants */
    const int E0 = 0;
    const int E2 = 2;
    const int E4 = 4;
    const int E6 = 6;
    const int E8 = 8;

/* statements */
    printf("%c %c %c %c %c\n", A, E, I, O, U);
    printf("%d %d %d %d %d\n", E0, E2, E4, E6, E8);
    printf("%d %d %d %d %d\n", 1, 3, 5, 7, 9);  /* odd numbers as literal constants */
    return 0;
} /* main */
