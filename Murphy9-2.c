/*
*****************************************************************************************************************
*                                 Name:            Pointers - Triple Linear, Multi-Level                        *
*                                 Version:         1.0                                                          *
*                                 Chapter:         9.2, Assignment (p. 608-9, #38)                              *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    25 Oct 15                                                    *
*                                 Last Modified:   27 Oct 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
* Creates a pointer structure that uses three variables and multiple levels of pointers to those variables, and *
* then multiplies the two inputted numbers together.  It then prints inputs and product using the pointers.     *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;                  //multiplicand
    int b;                  //multiplier
    int c;                  //product

    int*   x = &a;          //pointer to multiplicand

    int*   p = &b;          //pointer to multiplier
    int**  y = &p;          //pointer to pointer to multiplier

    int*   q = &c;          //pointer to product
    int**  r = &q;          //pointer to pointer to product
    int*** z = &r;          //pointer to pointer to pointer to product

    puts("Enter the multiplicand and multiplier to find the product:");
    puts("----------------------------------------------------------");

    printf("\nEnter an integer: \t");
    scanf("%d", x);
    printf("\nEnter an integer: \t");
    scanf("%d", *y);

    ***z = (*x) * (**y);

    printf("\n\n%d * %d = %d\n", *x, **y, ***z);

    return 0;
}
