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
    printf("pointer p ---> variable a\n");
    printf("\nEnter an integer for variable b: \t");
    scanf("%d", q);
    printf("pointer q ---> variable b\n");
    printf("\nEnter an integer for variable c: \t");
    scanf("%d", r);
    printf("pointer r ---> variable c\n");

    printf("\n\nYou entered:\n");
    printf("=============================================\n");
    printf("var a: %4d | address: %p | pointer: p\n", a, &a);
    printf("var b: %4d | address: %p | pointer: q\n", b, &b);
    printf("var c: %4d | address: %p | pointer: r\n", c, &c);

    printf("\n\nScrambling addresses...\n\n");
    p = &c;
    printf("pointer p ---> variable c\n");
    q = &a;
    printf("pointer q ---> variable a\n");
    r = &b;
    printf("pointer r ---> variable b\n\n");

    printf("var a deref *q: %4d | address in ptr q: %p | address of ptr q: %p\n", *q, q, &q);
    printf("var b deref *r: %4d | address in ptr r: %p | address of ptr r: %p\n", *r, r, &r);
    printf("var c deref *p: %4d | address in ptr p: %p | address of ptr p: %p\n", *p, p, &p);

    return 0;
}
