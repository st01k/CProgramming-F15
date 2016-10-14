/*
*****************************************************************************************************************
*                                 Name:            Pointers - Triple Linear, One Level                          *
*                                 Version:         1.0                                                          *
*                                 Chapter:         9.1, Assignment (p. 608-9, #37)                              *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    25 Oct 15                                                    *
*                                 Last Modified:   25 Oct 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
*          Creates a pointer structure that uses three variables and three pointers to those variables.         *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define FLUSH while (getchar() != '\n')

void getData (int* pa);

int main()
{
    int a;
    int* p = &a;

    getData(p);

    printf("\n\nYou entered:\n");
    printf("=============================================\n");
    printf("var a: %4d | address: %p | pointer: p\n", a, &a);

    return 0;
}

void getData (int* pa)
{
    int flag = 0;

    printf("\nEnter an integer for variable a: \t");
    flag = scanf("%d", pa);

    while (flag < 1)
    {
        FLUSH;
        printf("\a\nInvalid Response.  Please re-enter value: ");
        flag = scanf("%d", pa);
    }

    return;
}
