/*
**********************************************************************************************************************
*                                 Name:            English to Pig Latin Translator                                   *
*                                 Version:         0.9  (segmentation fault)                                         *
*                                 Chapter:         11.1, Assignment (p. 743, #41)                                    *
*                                 Author:          Casey Murphy                                                      *
*                                 Date Created:    13 Nov 15                                                         *
*                                 Last Modified:   16 Nov 15                                                         *
* ------------------------------------------------------------------------------------------------------------------ *
*  Translates an English sentence into Pig Latin.                                                                    *
* ------------------------------------------------------------------------------------------------------------------ *
*  NOTE:  I believe the segmentation fault has to do with the strtok function.  I attempted many fixes, including    *
*         removing calloc completely, but nothing seemed to work.  I read on StackOverflow that there were problems  *
*         with strtok handling white space.  Not entirely sure what the problem is, though.                          *
* http://stackoverflow.com/questions/7218625/what-are-the-differences-between-strtok-and-strsep-in-c/7219504#7219504 *
**********************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate (char* pWord);

int main (void)
{
    const int MAXLN = 81;

    char  eSentence[MAXLN];                 //user input sentence
    char* pESnt = eSentence;                //pointer to sentence
    char* token;                            //word holder

    printf("English to Pig Latin Translator\n\n");
    printf("Type a sentence in lower case letters, without punctuation, and press Enter: \n\n");
    gets(eSentence);
    printf("\n");

    token = strtok(pESnt, " ");             //token gets first word
    translate(token);                       //first word is translated

    while (token != NULL)
    {
        token = strtok(NULL, " ");          //token gets subsequent words
        translate(token);                   //words are translated as token is repopulated with new word
    }

    return 0;
}
//----------------------------------------------------------------------------
// translates and prints the word passed to it
void translate (char* pWord)
{
    const char* pVOWELS = "aeiou";

    int   diff;                                 //difference in mem addresses for attaching consonant prefix
    char* wToken;                               //word with consonant prefix removed & base of concatenation
    char* tWord;                                //temp word holder for token readdressing
    char* suffix = "ay";                        //'ay' suffix

    if (!(tWord = calloc((strlen(pWord) + 1), sizeof(char*)))) exit (1);    //allocates mem for temp word
    strncpy(tWord, pWord, strlen(pWord));       //copies current token to temp holder
    wToken = strpbrk(tWord, pVOWELS);           //finds first vowel and cuts off the preceeding characters
    diff = wToken - tWord;                      //finds how many letters were cut off
    strncat(wToken, tWord, diff);               //appends consonant prefix to wToken
    strcat(wToken, suffix);                     //appends suffix to wToken
    printf("%s ", wToken);                      //print wToken

    return;
}
/*----------------------------------------------------------------------------

English to Pig Latin Translator

Type a sentence in lower case letters, without punctuation, and press Enter:

alice is through the looking glass

aliceay isay oughthray ethay ookinglay assglay
Process returned -1073741819 (0xC0000005)   execution time : 8.583 s
Press any key to continue.
*/
