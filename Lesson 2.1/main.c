/*
************************************************************
*                  Fun with Constants                      *
*               Chapter 2, Assignment 1.1                  *
*                 Author: Casey Murphy                     *
*                Date Created: 27 Aug 15                   *
*               Last Modified: 27 Aug 15                   *
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
    const int e0 = 0;
    const int e2 = 2;
    const int e4 = 4;
    const int e6 = 6;
    const int e8 = 8;

/* statements */
    printf("%c %c %c %c %c\n", A, E, I, O, U);
    printf("%d %d %d %d %d\n", e0, e2, e4, e6, e8);
    printf("%d %d %d %d %d\n", 1, 3, 5, 7, 9);  /* odd numbers as literal constants */
    return 0;
} /* main */
