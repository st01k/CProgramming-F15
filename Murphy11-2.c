/*
*****************************************************************************************************************
*                                 Name:            Encoder/Decoder                                              *
*                                 Version:         1.0                                                          *
*                                 Chapter:         11.2, Assignment (p. 743, #43)                               *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    15 Nov 15                                                    *
*                                 Last Modified:   16 Nov 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
*  Menu driven encoder/decoder.  Reads key from file.  Key in file can be altered to whatever the user wants.   *
*  If it is altered to more than 100 characters make sure MAXCHAR is adjusted appropriately.                    *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FLUSH while (getchar() != '\n')
#define MAXLN 81    //maximum user sentence length
#define MAXCHAR 100 //maximum characters for key map, change if key is altered to more than 99 characters/array

char menu    (void);
void loadKey (char* alpha, char* code);
void decode  (char* alpha, char* code);
void encode  (char* alpha, char* code);
char repeat  (void);

int main (void)
{
    char menuSel;                   //user input, menu selection
    char again;                     //user input to repeat program
    char alpha[MAXCHAR];            //array from file of alphabet
    char code [MAXCHAR];            //array from file of mapped code to alphabet

    do
    {
        menuSel = menu();
        if (menuSel == 'd') decode(alpha, code);
        if (menuSel == 'e') encode(alpha, code);
        again = repeat();
    } while (again == 'y');

    return 0;
}
//----------------------------------------------------------------------------
// interactive menu with validation, returns selection
char menu()
{
    char input;

    puts("\n\nMessage Encoder/Decoder Menu");
    puts("\nE) Encode a message\nD) Decode a message\nQ) Quit\n");
    printf("Enter your selection: ");
    scanf(" %c", &input);
    input = tolower(input);

    switch (input)
    {
        case 'd' :  break;
        case 'e' :  break;
        case 'q' :  exit (0);
                    break;
        default  :  while (input != 'd' && input != 'e')
                    {
                        printf("\aInvalid Response. Re-enter your answer: ");
                        FLUSH;
                        scanf(" %c", &input);
                        if (input == 'q') exit(0);
                    }
    }

    return input;
}
//----------------------------------------------------------------------------
//  maps alphabet and code into separate arrays, takes array pointers
void loadKey(char* alpha, char* code)
{
    FILE* pFile;
    char  cur;
    int   i;

    if (!(pFile = fopen("key.txt", "r")))
    {
        printf ("\aError opening file: ensure that key.txt exists.\n");
        exit (1);
    } // if file open error

    i = 0;
    while ((cur = fgetc(pFile)) != '\n')
    {
        alpha[i] = cur;
        i++;
    }

    i = 0;
    while ((cur = fgetc(pFile)) != EOF)
    {
        code[i] = cur;
        i++;
    }

    fclose(pFile);

    return;
}
//----------------------------------------------------------------------------
//  decodes coded message to english, takes mapped arrays
void decode(char* alpha, char* code)
{
    int   len;
    int   diff;
    char* ptr;
    char  message[MAXLN];

    loadKey(alpha, code);

    printf("\nEnter the message to be decoded and press enter:\n\n");
    FLUSH;
    gets(message);

    char* english = message;
    len = strlen(message);

    for (int i = 0; i < len; i++)
    {
        ptr = strchr(code, message[i]);
        diff = ptr - code;
        english[i] = alpha[diff];
    }

    printf("\n%s\n", english);

    return;
}
//----------------------------------------------------------------------------
// encodes english to coded message, takes mapped arrays
void encode(char* alpha, char* code)
{
    int   len;
    int   diff;
    char* ptr;
    char  message[MAXLN];

    loadKey(alpha, code);

    printf("\nEnter the message to be encoded and press enter:\n\n");
    FLUSH;
    gets(message);

    char* coded = message;
    len = strlen(message);

    for (int i = 0; i < len; i++)
    {
        ptr = strchr(alpha, message[i]);
        diff = ptr - alpha;
        coded[i] = code[diff];
    }

    printf("\n%s\n", coded);

    return;
}
//----------------------------------------------------------------------------
// repeat dialog with validation, returns user input
char repeat(void)
{
    char input;

    printf("\n\nWould you like to run this program again (Y/N): ");
    scanf(" %c", &input);
    input = tolower(input);

    switch (input)
    {
        case 'y' :  break;
        case 'n' :  break;
        default  :  while (input != 'y' && input != 'n')
                    {
                        printf("\aInvalid Response. Re-enter your answer: ");
                        FLUSH;
                        scanf(" %c", &input);
                        if (input == 'n')
                            exit(0);
                    }
    }


    return input;
}
/*----------------------------------------------------------------------------
// Output:

Message Encoder/Decoder Menu

E) Encode a message
D) Decode a message
Q) Quit

Enter your selection: d

Enter the message to be decoded and press enter:

wnwlsvplm, ln a

did you get itw


Would you like to run this program again (Y/N): y


Message Encoder/Decoder Menu

E) Encode a message
D) Decode a message
Q) Quit

Enter your selection: d

Enter the message to be decoded and press enter:

?q.w,emrntbxyuv!ico pza;sdlfkgjh

abcdefghijklmnopqrstuvwxyz .,?!;


Would you like to run this program again (Y/N): n

Process returned 0 (0x0)   execution time : 108.165 s
Press any key to continue.
*/
