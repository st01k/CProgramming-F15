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

int main()
{
    int a;
    int b;
    int c;

    int* p = &a;
    int* q = &b;
    int* r = &c;

    printf("\nEnter an integer for variable a: \t");
    scanf("%d", p);
    printf("\nEnter an integer for variable b: \t");
    scanf("%d", q);
    printf("\nEnter an integer for variable c: \t");
    scanf("%d", r);

    printf("\n\nYou entered:\n");
    printf("============\n");
    printf("Var a: %5d @ pointer p | address: %p\n", a, &a);
    printf("Var b: %5d @ pointer q | address: %p\n", b, &b);
    printf("Var c: %5d @ pointer r | address: %p\n", c, &c);

    printf("\n\nScrambling addresses...\n\n");
    p = &c;
    printf("pointer p ---> variable c\n");
    q = &a;
    printf("pointer q ---> variable a\n");
    r = &b;
    printf("pointer r ---> variable b\n\n");

    printf("Var a @ pointer q - Contents: %5d | address @ pointer q: %p\n", *q, q);
    printf("Var b @ pointer r - Contents: %5d | address @ pointer r: %p\n", *r, r);
    printf("Var c @ pointer p - Contents: %5d | address @ pointer p: %p\n", *p, p);

    return 0;
}
