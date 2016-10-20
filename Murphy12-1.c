/*
*****************************************************************************************************************
*                                 Name:            Deck Construction and Shuffling                              *
*                                 Version:         1.0                                                          *
*                                 Chapter:         12.1, Assignment (p. 818, #42)                               *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    26 Nov 15                                                    *
*                                 Last Modified:   27 Nov 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
*  Using an array of structures, this program builds, shuffles, and deals a deck of standard playing cards      *
*  as per the algorithm laid out in the referenced problem, in the book.                                        *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SZ 52          //deck size
#define PLAYERS 4           //number of players to deal for
#define HEART   0x03        //hex value for heart character
#define DIAMOND 0x04        //hex value for diamond character
#define CLUB    0x05        //hex value for club character
#define SPADE   0x06        //hex value for spade character

typedef struct              //card structure
{
    int rank;
    int suit;
}   CARD;

void initDeck (CARD* deck);
void shuffle  (CARD* deck, CARD* shuffled);
void deal     (CARD* shuffled);

int main()
{
    CARD deck[DECK_SZ];         //initialized deck
    CARD shuffled[DECK_SZ];     //shuffled deck

    initDeck(deck);
    shuffle(deck, shuffled);
    deal(shuffled);

    return 0;
}
//---------------------------------------------------------------------------------------------
// initializes deck
void initDeck (CARD* deck)
{
    for (int i = 0; i < DECK_SZ; i++)
    {
        deck[i].rank = (i % 13);
        deck[i].suit = (i / 13);
    }
}
//---------------------------------------------------------------------------------------------
// takes initialized deck, creates shuffled deck
void shuffle  (CARD* deck, CARD* shuffled)
{
    int randNum;
    int shufOrder[DECK_SZ];
	int haveRand[DECK_SZ] = {0};

    srand (time(NULL));
    for (int i = 0; i < DECK_SZ; i++)
	{
        do randNum = rand() % DECK_SZ;
        while (haveRand[randNum] == 1);

        haveRand[randNum] = 1;
	    shufOrder[i] = randNum;
        shuffled[i] = deck[shufOrder[i]];
    }
}
//---------------------------------------------------------------------------------------------
// deals cards according to number of players defined using shuffled deck
void deal (CARD* shuffled)
{
    const char *face[] = {"A", "2", "3", "4", "5", "6", "7",
                          "8", "9", "10", "J", "Q", "K"};
    const char symbol[] = {HEART, DIAMOND, CLUB, SPADE};

    printf("    Deck shuffled... dealing for %d players: \n", PLAYERS);
    printf("    =======================================\n\n");

    for (int i = 0; i < DECK_SZ; i++)
    {
        printf("\t%3s %c", face[shuffled[i].rank], symbol[shuffled[i].suit]);
        if (!((i + 1) % PLAYERS)) printf ("\n\n");
    }
}
