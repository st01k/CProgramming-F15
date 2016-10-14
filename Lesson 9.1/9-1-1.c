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
#include <windows.h>

#define FLUSH while (getchar() != '\n')

void getData (int* input, char varID);
void separator (void);
void preScramble (char varID, char ptrID, int* var);
void postScramble (char varID, char ptrID, int* ptr);

int main()
{
    int a;
    int b;
    int c;

    int* p = &a;
    int* q = &b;
    int* r = &c;

    getData(p, 'a');
    getData(q, 'b');
    getData(r, 'c');

    printf("\n\nYou entered:\n");
    separator();
    preScramble('a', 'p', &a);
    preScramble('b', 'q', &b);
    preScramble('c', 'r', &c);
    //printf("var a: %4d ---> pointer p | address of a: %p\n", a, &a);
    //printf("var b: %4d ---> pointer q | address of b: %p\n", b, &b);
    //printf("var c: %4d ---> pointer r | address of c: %p\n", c, &c);

    printf("\n\nScrambling addresses...\n\n\n");
    Sleep(500);
    p = &c;
    q = &a;
    r = &b;

    separator();
    postScramble('a', 'q', q);
    postScramble('b', 'r', r);
    postScramble('c', 'p', p);
    //printf("var a: %4d ---> pointer q | address in q: %p\n", *q, q);
    //printf("var b: %4d ---> pointer r | address in r: %p\n", *r, r);
    //printf("var c: %4d ---> pointer p | address in p: %p\n", *p, p);

    return 0;
}
//---------------------------------------------------------------------------------------------
//gets user input for integer variable and checks for valid response
void getData (int* input, char varID)
{
    int flag = 0;

    printf("\nEnter one integer value for variable %c:\t", varID);
    flag = scanf("%d", input);
    FLUSH;

    while (flag < 1)
    {
        FLUSH;
        printf("\a\nInvalid Response.  Re-enter value for %c: ", varID);
        flag = scanf("%d", input);
    }

    return;
}
//---------------------------------------------------------------------------------------------
// prints formatted separator
void separator (void)
{
    printf("===================================================\n");

    return;
}
//---------------------------------------------------------------------------------------------
// print pre scramble results
void preScramble (char varID, char ptrID, int* var)
{
    printf("var %c: %4d ---> pointer %c | address of %c: %p\n", varID, *var, ptrID, varID, var);

    return;
}
//---------------------------------------------------------------------------------------------
// prints post scramble results
void postScramble (char varID, char ptrID, int* ptr)
{
    printf("var %c: %4d ---> pointer %c | address in q: %p\n", varID, *ptr, ptrID, ptr);

    return;
}
