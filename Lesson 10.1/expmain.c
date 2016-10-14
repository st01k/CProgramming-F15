/*
*****************************************************************************************************************
*                                 Name:            Bridge Deck for 4 players                                    *
*                                 Version:         1.0                                                          *
*                                 Chapter:         10.1, Assignment (p. 664, #51)                               *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    30 Oct 15                                                    *
*                                 Last Modified:   31 Oct 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
*  Bridge deck simulation.  A deck of cards is shuffled and dealt completely out to 4 players, each receiving   *
*  thirteen cards.  Players are North, South, East, and West.                                                   *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>               //for srand

#define DECK        52
#define CLUB        0x05        //hex value for club character
#define CMIN        1
#define CMAX        13
#define DIAMOND     0x04        //hex value for diamond character
#define DMIN        14
#define DMAX        26
#define HEART       0x03        //hex value for heart character
#define HMIN        27
#define HMAX        39
#define SPADE       0x06        //hex value for spade character
#define SMIN        40
#define SMAX        52
#define NUMPLAYERS  4
#define HAND        DECK / NUMPLAYERS

void intro       (void);
void initDeck    (int* oDeck);
void shuffleDeck (int  oDeck[], int* sDeck);
void dealDeck    (int  sDeck[], int dealt[HAND][NUMPLAYERS]);

int main()
{
    int ordDeck[DECK] = {0};            //ordered deck
    int shfDeck[DECK] = {0};            //shuffled deck
    int cardTable[HAND][NUMPLAYERS];    //table: rows - card in hand, columns - each player

    intro();
    initDeck(ordDeck);
    puts("Press Enter to shuffle the deck...");
    getchar();
    shuffleDeck(ordDeck, shfDeck);
    puts("Deck shuffled.  Press Enter to deal each round of cards...\n");
    getchar();
    dealDeck(shfDeck, cardTable);

    return 0;
}
//---------------------------------------------------------------------------------------------
// prints program introduction
void intro (void)
{
    puts("\nThis program shuffles and deals out a deck of cards for 4 Bridge players.");
    printf("=========================================================================\n");
    printf("\n");

    return;
}
//---------------------------------------------------------------------------------------------
// creates an array of numbers representing the entire deck (1-52)
void initDeck (int* oDeck)
{
    for (int i = 0; i < DECK; i++)
    {
        oDeck[i] = i + 1;
    }

    return;
}
//---------------------------------------------------------------------------------------------
// ordered deck passed in, array created with random elements (1-52), shuffled deck created
// from shifting elements in ordered deck according to random element array
void shuffleDeck (int oDeck[], int* sDeck)
{
	int randNum;
	int haveRand[DECK] = {0};
	int rndElmt [DECK] = {0};

	srand (time(NULL));
    for (int i = DECK + 1; i > 0; i--)
	{
        randNum = rand() % i;
	    rndElmt[i] = randNum;
    }

	for (int current = 0; current < DECK; current++)
	{
        sDeck[current] = oDeck[(rndElmt[current])];
    }

    return;
}
//---------------------------------------------------------------------------------------------
// deals card to each player, prints results of the deal per hand
void dealDeck (int sDeck[], int dealt[HAND][NUMPLAYERS])
{
    int suit;
    int rank;
    int i = 0;      //current card in deck counter
    int x = 0;      //used only as false lvalue placeholder in ternary statements

    printf("\t\tNorth\tEast\tSouth\tWest\n");
    printf("\t\t-----\t----\t-----\t----\n\n");

    for (int card = 0; card < HAND; card++)
    {
        printf("Card %2d:\t", card + 1);

        for (int player = 0; player < NUMPLAYERS; player++)
        {
            dealt[card][player] = sDeck[i], i++;

            rank = (dealt[card][player] % 13) + 1;
            switch (rank)
            {
                case  1 : printf(" A ");
                          break;
                case 11 : printf(" J ");
                          break;
                case 12 : printf(" Q ");
                          break;
                case 13 : printf(" K ");
                          break;
                default : printf("%2d ", rank);
                          break;
            } //switch rank

            (dealt[card][player] >= CMIN && dealt[card][player] <= CMAX) ? suit = 1 : x++;  //clubs
            (dealt[card][player] >= DMIN && dealt[card][player] <= DMAX) ? suit = 2 : x++;  //diamonds
            (dealt[card][player] >= HMIN && dealt[card][player] <= HMAX) ? suit = 3 : x++;  //hearts
            (dealt[card][player] >= SMIN && dealt[card][player] <= SMAX) ? suit = 4 : x++;  //spades
            switch (suit)
            {
                case 1  : printf("%c\t", CLUB);
                          break;
                case 2  : printf("%c\t", DIAMOND);
                          break;
                case 3  : printf("%c\t", HEART);
                          break;
                case 4  : printf("%c\t", SPADE);
                          break;
                default : printf("\a\nERROR.  Terminating.\n");
                          exit(1);
            } //switch suit
        } //for player

        printf("\t...");
        getchar();
        printf("\n");
    } //for card

    return;
}
