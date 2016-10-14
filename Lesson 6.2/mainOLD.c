/*
************************************************************
*                  Calculate Pi - Bonus                    *
*               Chapter 6, Assignment 6.2                  *
*                 Author: Casey Murphy                     *
*                Date Created: 28 Sep 15                   *
*               Last Modified: 28 Sep 15                   *
*   Calculates Pi based on formula provided in program     *
************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function declarations
int             userInput   (void);                         //gets input
long double     calcPi      (int ip);                       //calculates pi
void            result      (int ip, long double fpi);      //prints result

int main()
{
    //local declarations
    int           input;                                    //user input
    long double   pi;                                       //value of pi

    //statements
    input = userInput();
    pi    = calcPi (input);
    result (input, pi);

    return 0;
}
//----------------------------------------------------------------------------
//gets input from user and returns it to main
int     userInput   (void)
{
    int  ip;

    printf  ("-------------------------------------------------------------------------------\n");
    printf  ("This program will calculate the value of Pi using the following formula: \n\n");
    printf  ("Pi = sqrt { 6 [(1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2)]} ]\n\n");
    printf  ("Enter the limit as an integer: ");
    scanf   ("%d", &ip);

    return ip;
}
//----------------------------------------------------------------------------
//gets input from main, calculates pi and returns value to main
long double    calcPi      (int ip)
{
    long double fpi;
    long double holder;
    long double pholder = 0.0;

    for (int i = 1; i <= ip; i++)
    {
        holder = (1.0 / (pow (i, 2.0)));
        pholder += holder;
    }
    fpi = sqrtl (6.0 * pholder);

    return fpi;
}
//----------------------------------------------------------------------------
//gets input and pi from main and prints them
void    result      (int ip, long double fpi)
{
    printf  ("-------------------------------------------------------------------------------\n");
    printf  ("Pi calculated to the limit of %d is: %Lf\n", ip, fpi);
    printf  ("-------------------------------------------------------------------------------\n\n");

    return;
}

/*
OUTPUT:
-------

1)
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt { 6 [(1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2)]} ]

Enter the limit as an integer: 5
-------------------------------------------------------------------------------
Pi calculated to the limit of 5 is: 2.963388
-------------------------------------------------------------------------------

2)
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt { 6 [(1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2)]} ]

Enter the limit as an integer: 10
-------------------------------------------------------------------------------
Pi calculated to the limit of 10 is: 3.049362
-------------------------------------------------------------------------------

3)
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt { 6 [(1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2)]} ]

Enter the limit as an integer: 1000000
-------------------------------------------------------------------------------
Pi calculated to the limit of 1000000 is: 3.141592
-------------------------------------------------------------------------------

4)
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt { 6 [(1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2)]} ]

Enter the limit as an integer: 827790
-------------------------------------------------------------------------------
Pi calculated to the limit of 827790 is: 3.141592
-------------------------------------------------------------------------------

5)
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt { 6 [(1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2)]} ]

Enter the limit as an integer: 827789
-------------------------------------------------------------------------------
Pi calculated to the limit of 827789 is: 3.141591
-------------------------------------------------------------------------------
*/
