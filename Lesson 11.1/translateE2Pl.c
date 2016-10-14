#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void initialize(char english[], char piglatin[]);
void readinput(char english[]);
int countwords(char english[]);
void convert(int words, char english[], char piglatin[]);
void writeoutput(char piglatin[]);

int main(void)
{
    char english[80], piglatin[80];
    int words;
    printf("\nPig Latin Translator in C\n\n");
    printf( "Type \'END\' when finished\n\n");

    do
    {
        /* processing a new line of text */
        initialize(english, piglatin);
        readinput(english);

        /* testing stopping condition */
        if (toupper(english[0]) == 'E' && toupper(english[1]) == 'N' && toupper(english[2]) == 'D')
            break;

        /* count the number of words in the line */
        words = countwords(english);

        /* Now Pig Latin Translator in C converts English to Pig Latin */
        convert(words, english, piglatin);
        writeoutput(piglatin);
    }
    while (words >= 0);
    printf("\naveHa aa icena ayda (Have a nice day)\n");
}


/* initializing character arrays with blank spaces */
void initialize(char english[], char piglatin[])
{
    int count;
    for (count = 0; count < 80; ++count)
        english[count] = piglatin[count] = ' ';
    return;
}


/* reading one line of text in English */
void readinput(char english[])
{
    int count = 0;
    char c;
    while (( c = getchar()) != '\n')
    {
        english[count] = c;
        ++count;
    }
    return;
}


/* scanning the given message or line of text and determining the number of words in it */
int countwords(char english[])
{
    int count, words = 1;
    for (count = 0; count < 79; ++count)
    if (english[count] == ' ' && english[count + 1] != ' ')
        ++words;
    return (words);
}


/* now Pig Latin translator in C coverts each word into Pig Latin */
void convert(int words, char english[], char piglatin[])
{
    int n, count;
    int m1 = 0; /* m1 indicates the position of beginning of each word */
    int m2; /* m2 indicates the end of the word */

    /* convert each word */
    for (n = 1; n <= words; ++n)
    {
        /* locating the end of the current word */
        count = m1 ;
        while (english[count] != ' ')
            m2 = count++;

        /* transposing the first letter of each word and adding 'a' at the end */
        for (count = m1 ; count < m2; ++count)
            piglatin[count + (n - 1)] = english[count + 1];
        piglatin[m2 + (n - 1)] = english[m1];
        piglatin[m2 + n] = 'a'; /* adding 'a' at the end */

        /* reseting the initial marker */
        m1 = m2 + 2;
    }
    return;
}


/* now Pig Latin translator in C displays the line of English text in Pig Latin */
void writeoutput(char piglatin[])
{
    int count = 0;
    for (count = 0; count < 80; ++count)
        putchar(piglatin[count]);
    printf("\n");
    return;
}
