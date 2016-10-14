/*
*****************************************************************************************************************
*                                 Name:            Text Analyzer                                                *
*                                 Version:         1.1                                                          *
*                                 Chapter:         7, Assignment (p. 455, #44)                                  *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    6 Oct 15                                                     *
*                                 Last Modified:   7 Oct 15                                                     *
* ------------------------------------------------------------------------------------------------------------- *
*    Menu-driven text file analyzer that finds character count, word count, line count, and sentence count.     *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>                      //for islower
#include <stdbool.h>                    //for invalid flag

#define WHT_SPC\
        (cur == ' ' || cur == '\n' || cur == '\t')

//function declarations - see function definition for description
void greeting    (void);
char menu        (void);
void selectionSW (FILE* spFile, char input, int* cCountPtr,
                  int* wCountPtr, int* lCountPtr, int* sCountPtr);
void countChars  (FILE* spFile, int* cCountPtr);
void countWords  (FILE* spFile, int* wCountPtr);
void countLines  (FILE* spFile, int* lCountPtr);
void countSent   (FILE* spFile, int* sCountPtr);
void printAll    (FILE* spFile, int* cCount, int* wCount,
                  int* lCount, int* sCount);

int main (void)
{
    FILE*   spFile;                     //file being read
    char    selection;                  //user's selection
    int     charCount = 0;              //character count
    int     wordCount = 0;              //word count
    int     lineCount = 0;              //line count
    int     sentCount = 0;              //sentence count

    greeting    ();
    selection   = menu ();
    selectionSW (spFile, selection, &charCount,
                 &wordCount, &lineCount, &sentCount);

    return 0;
} // main

//----------------------------------------------------------------------------
// prints greeting to user
void greeting (void)
{
    printf ("\n\t\tWelcome to the text file analyzer.\n\n"                          );
    printf ("------------------------------------------------------------------\n"  );
    printf ("Usage: Save a copy of whatever text file you would like to analyze\n"  );
    printf ("as testfile.txt inside the directory where this file is to use it.\n"  );
    printf ("------------------------------------------------------------------\n\n");
}
//----------------------------------------------------------------------------
// looped menu, returns user's selection
char menu (void)
{
    char input;
    bool invalidFlag;

    printf ("\tC) Count characters in a text file\n"                                );
    printf ("\tW) Count words in a text file\n"                                     );
    printf ("\tL) Count lines in a text file\n"                                     );
    printf ("\tS) Count sentences in a text file\n"                                 );
    printf ("\tA) Count all of the above options in a text file\n"                  );
    printf ("\tQ) Quit\n\n"                                                         );
    printf ("------------------------------------------------------------------\n\n");

    do
    {
        invalidFlag = false;
        printf ("Enter your selection: "                  );
        scanf  (" %c", &input);
        printf ("======================================\n");
        input = tolower (input);

        switch (input)
        {
            case 'c' :  break;
            case 'w' :  break;
            case 'l' :  break;
            case 's' :  break;
            case 'a' :  break;
            case 'q' :  exit (0);
            default  :  printf ("\n\aInvalid Response.  Please try again.\n");
                        printf ("======================================\n"  );
                        invalidFlag = true;
                        break;
        } // switch
    } while (invalidFlag);

    return input;
}
//----------------------------------------------------------------------------
//  switch that calls subfunctions to calculate values for user choice
void selectionSW (FILE* spFile, char input, int* cCountPtr,
                  int* wCountPtr, int* lCountPtr, int* sCountPtr)
{
    switch (input)
        {
            case 'c' :  countChars(spFile, cCountPtr);
                        break;
            case 'w' :  countWords(spFile, wCountPtr);
                        break;
            case 'l' :  countLines(spFile, lCountPtr);
                        break;
            case 's' :  countSent(spFile, sCountPtr);
                        break;
            case 'a' :  printAll(spFile, cCountPtr, wCountPtr, lCountPtr, sCountPtr);
                        break;
            default  :  printf("\n\aUnknown Error.  Terminating Program.\n\n");
                        exit (1);
        }
}
//----------------------------------------------------------------------------
//  counts and prints number of characters in a text file
void countChars (FILE* spFile, int* cCountPtr)
{
    char    cur;

    if (!(spFile = fopen("testfile.txt", "r")))
    {
        printf ("Error opening file\n");
        exit (2);
    } // if file open error

    while ((cur = fgetc(spFile)) != EOF)
    {
        *cCountPtr += 1;
    }

    fclose  (spFile);
    printf ("\nCharacters in file:\t %d\n", *cCountPtr);
}
//----------------------------------------------------------------------------
//  counts and prints number of words in a text file
void countWords (FILE* spFile, int* wCountPtr)
{
    int  cur;
    char word = 'O';    // O is white space, I is words

    if (!(spFile = fopen("testfile.txt", "r")))
    {
        printf ("Error opening file\n");
        exit (2);
    } // if file open error

    while ((cur = fgetc(spFile)) != EOF)
    {
        if (WHT_SPC)
            word = 'O';
        else
            if (word == 'O')
            {
                *wCountPtr += 1;
                word = 'I';
            } // if
    } // while

    fclose  (spFile);
    printf ("\nWords in file:\t\t %d\n", *wCountPtr);
}
//----------------------------------------------------------------------------
//  counts and prints number of lines in a text file
void countLines (FILE* spFile, int* lCountPtr)
{
    int cur;
    int preChar;

    if (!(spFile = fopen("testfile.txt", "r")))
    {
        printf ("Error opening file\n");
        exit (2);
    } // if file open error

    while ((cur = fgetc(spFile)) != EOF)
    {
        if (cur == '\n')
            *lCountPtr += 1;
        preChar = cur;
    } // while

    if (preChar != '\n')
        *lCountPtr += 1;

    fclose  (spFile);
    printf ("\nLines in file:\t\t %d\n", *lCountPtr);
}
//----------------------------------------------------------------------------
//  counts and prints number of sentences in a text file
void countSent (FILE* spFile, int* sCountPtr)
{
    int cur;

    if (!(spFile = fopen("testfile.txt", "r")))
    {
        printf ("Error opening file\n");
        exit (2);
    } // if file open error

    while ((cur = fgetc(spFile)) != EOF)
    {
        if (cur == '.')
            *sCountPtr += 1;
    } // while

    fclose  (spFile);
    printf ("\nSentences in file:\t %d\n", *sCountPtr);
}
//----------------------------------------------------------------------------
//  counts and prints all options
void printAll (FILE* spFile, int* cCountPtr, int* wCountPtr,
               int* lCountPtr, int* sCountPtr)
{
    countChars (spFile, cCountPtr);
    countWords (spFile, wCountPtr);
    countLines (spFile, lCountPtr);
    countSent  (spFile, sCountPtr);
}
