/*
*****************************************************************************************************************
*                                 Name:            Pointers - Triple Linear, One Level                          *
*                                 Version:         2.0                                                          *
*                                 Chapter:         9.1, Assignment (p. 608-9, #37)                              *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    25 Oct 15                                                    *
*                                 Last Modified:   27 Oct 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
*          Creates a pointer structure that uses three variables and three pointers to those variables.         *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define FLUSH while (getchar() != '\n')

void getData        (int* input, char varID);
void preScramble    (char varID, char ptrID, int* var);
void postScramble   (char varID, char ptrID, int* ptr);
void separator      (void);

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

    q = &a;
    r = &b;
    p = &c;

    printf("\n\nScrambled Pointers:\n");
    separator();

    postScramble('a', 'q', q);
    postScramble('b', 'r', r);
    postScramble('c', 'p', p);

    return 0;
}
//---------------------------------------------------------------------------------------------
//gets user input for integer variable and checks for valid response
void getData (int* input, char varID)
{
    int flag = 0;

    printf("\nEnter one integer value for variable %c:\t", varID);
    flag = scanf("%d", input);
    //clears stream if more than one entry is made, but makes an extra <CR> necessary with an invalid response.
    //FLUSH;

    while (flag < 1)
    {
        FLUSH;
        printf("\a\nInvalid Response.  Re-enter value for %c: ", varID);
        flag = scanf("%d", input);
    }

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
    printf("var %c: %4d ---> pointer %c | address in %c: %p\n", varID, *ptr, ptrID, ptrID, ptr);

    return;
}
//---------------------------------------------------------------------------------------------
// prints formatted separator
void separator (void)
{
    printf("===================================================\n");

    return;
}
