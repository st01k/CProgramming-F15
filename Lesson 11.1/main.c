
/*
*****************************************************************************************************************
*                                 Name:            English to Pig Latin Translator                              *
*                                 Version:         0.1                                                          *
*                                 Chapter:         11.1, Assignment (p. 743, #41)                               *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    13 Nov 15                                                    *
*                                 Last Modified:   13 Nov 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
*  Translates an English sentence into Pig Latin.                                                               *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate (char* pWord, char* tWord);

int main (void)
{
    const int MAXLN = 81;
    const int MAXWDLENGTH = 16;

    char  eSentence[MAXLN];
    char* pESnt = eSentence;
    char* token;
    char* tempWord;

        printf("English to Pig Latin Translator\n\n");
        printf("Type a complete sentence without punctuation and press Enter: \n\n");
        gets(eSentence);
        printf("\n");

        token = strtok(pESnt, " ");
        tempWord = calloc(MAXWDLENGTH, sizeof(char*));
        translate(token, tempWord);

        while (token != NULL)
        {
            token = strtok(NULL, " ");
            translate(token, tempWord);
        }

        free(tempWord);

    return 0;
}

void translate (char* pWord, char* tWord)
{
    const char* pVOWELS = "aeiou";

    int   diff;
    char* wToken;
    char* suffix = "ay";

    strncpy(tWord, pWord, strlen(pWord));
    wToken = strpbrk(tWord, pVOWELS);
    diff = wToken - tWord;
    strncat(wToken, tWord, diff);
    strcat(wToken, suffix);
    printf("%s ", wToken);

    return;
}
