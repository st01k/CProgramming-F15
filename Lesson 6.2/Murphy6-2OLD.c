/*
*****************************************************************************************************************
*                                 Name:            Calculate Pi                                                 *
*                                 Version:         1.2                                                          *
*                                 Chapter:         6, Bonus                                                     *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    28 Sep 15                                                    *
*                                 Last Modified:   30 Sep 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
*                         Calculates Pi based on formula provided in program                                    *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function declarations
int            userInput   (void);                         //gets input
long double    calcPi      (int lim);                      //calculates pi
void           result      (int lim, long double fpi);     //prints result

int main()
{
    //local declarations
    int         limit;                                      //user input
    long double pi;                                         //value of pi

    //statements
    limit  = userInput();
    pi     = calcPi (limit);
    result (limit, pi);

    return 0;
}
//----------------------------------------------------------------------------
//gets limit input from user and returns it to main
int     userInput   (void)
{
    int  ip;

    printf  ("-------------------------------------------------------------------------------\n");
    printf  ("This program will calculate the value of Pi using the following formula: \n\n"    );
    printf  ("Pi = sqrt { 6 [ 1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2) ] }\n\n"          );
    printf  ("Enter the limit as an integer: "                                                  );
    scanf   ("%d", &ip);

    return ip;
}
//----------------------------------------------------------------------------
//gets limit input from main, calculates pi w/limit and returns value to main
long double    calcPi      (int lim)
{
    long double fpi;
    long double holder;
    long double pholder = 0.0;

    for (int i = 1; i <= lim; i++)
    {
        holder   = (1.0 / (pow (i, 2.0)));
        pholder += holder;
    }
    fpi = sqrtl (6.0 * pholder);

    return fpi;
}
//----------------------------------------------------------------------------
//gets input and calculated pi from main and prints results
void    result      (int lim, long double fpi)
{
    printf  ("-------------------------------------------------------------------------------\n"  );
    printf  ("Pi calculated to the limit of %d is:  %Lf\n", lim, fpi                              );
    printf  ("-------------------------------------------------------------------------------\n\n");

    return;
}

/*OUTPUT:
---------

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

4) start of pico accuracy (6)
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt { 6 [(1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2)]} ]

Enter the limit as an integer: 827790
-------------------------------------------------------------------------------
Pi calculated to the limit of 827790 is: 3.141592
-------------------------------------------------------------------------------

5) end of nano accuracy (5)
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt { 6 [(1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2)]} ]

Enter the limit as an integer: 827789
-------------------------------------------------------------------------------
Pi calculated to the limit of 827789 is: 3.141591
-------------------------------------------------------------------------------

6)  odd that limit in the hundred millions strayed accuracy??

-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt ( 6 { [1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2) ] } )

Enter the limit as an integer: 123123123
-------------------------------------------------------------------------------
Pi calculated to the limit of 123123123 is: 3.141593
-------------------------------------------------------------------------------

7) zero
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt ( 6 { [1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2) ] } )

Enter the limit as an integer: 0
-------------------------------------------------------------------------------
Pi calculated to the limit of 0 is:  0.000000
-------------------------------------------------------------------------------

8) negative value
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt ( 6 { [1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2) ] } )

Enter the limit as an integer: -1
-------------------------------------------------------------------------------
Pi calculated to the limit of -1 is:  0.000000
-------------------------------------------------------------------------------

9) decimal value
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt ( 6 { [1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2) ] } )

Enter the limit as an integer: .45
-------------------------------------------------------------------------------
Pi calculated to the limit of 2686916 is:  3.141592
-------------------------------------------------------------------------------

10) negative decimal
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt ( 6 { [1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2) ] } )

Enter the limit as an integer: -0.45
-------------------------------------------------------------------------------
Pi calculated to the limit of 0 is:  0.000000
-------------------------------------------------------------------------------

11) negative decimal w/o preceding 0
-------------------------------------------------------------------------------
This program will calculate the value of Pi using the following formula:

Pi = sqrt ( 6 { [1/(1^2) + 1/(2^2) + 1/(3^2) + ... + 1/(limit^2) ] } )

Enter the limit as an integer: -.45
-------------------------------------------------------------------------------
Pi calculated to the limit of 2686916 is:  3.141592
-------------------------------------------------------------------------------
*/

