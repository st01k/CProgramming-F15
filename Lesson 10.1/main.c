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
#define CLUB        0x05
#define CMIN        1
#define CMAX        13
#define DIAMOND     0x04
#define DMIN        14
#define DMAX        26
#define HEART       0x03
#define HMIN        27
#define HMAX        39
#define SPADE       0x06
#define SMIN        40
#define SMAX        52
#define NUMPLAYERS  4
#define HAND        DECK / NUMPLAYERS

void intro       (void);
void separator   (void);
void initDeck    (int* oDeck);
void shuffleDeck (int  oDeck[], int* sDeck);
void dealDeck    (int  sDeck[], int dealt[HAND][NUMPLAYERS]);
void printHands  (int  dealt[NUMPLAYERS][HAND]);

int main()
{
    int ordDeck[DECK] = {0};
    int shfDeck[DECK] = {0};
    int cardTable[HAND][NUMPLAYERS];

    intro();
    initDeck(ordDeck);
    puts("Press Enter to shuffle the deck...");
    getchar();
    shuffleDeck(ordDeck, shfDeck);
    puts("Deck shuffled.  Press Enter to deal the cards to each player...");
    getchar();
    dealDeck(shfDeck, cardTable);
    //printHands(cardTable);

    return 0;
}
//---------------------------------------------------------------------------------------------
//
void intro (void)
{
    puts("This program shuffles and deals out a deck of cards for 4 Bridge players.");
    separator();
    printf("\n");

    return;
}
//---------------------------------------------------------------------------------------------
// prints formatted separator
void separator (void)
{
    printf("=========================================================================\n");

    return;
}
//---------------------------------------------------------------------------------------------
//
void initDeck (int* oDeck)
{
    for (int i = 0; i < DECK; i++)
    {
        oDeck[i] = i + 1;
//printf("position: %2d | value: %2d\n", i, oDeck[i]);
    }

    return;
}
//---------------------------------------------------------------------------------------------
//
void shuffleDeck (int oDeck[], int* sDeck)
{
	int randNum;
	int haveRand[DECK] = {0};
	int rndElmt [DECK] = {0};

	srand (time(NULL));
    for (int i = 0; i < DECK; i++)
	{
        do
	    {
            randNum = rand() % DECK;
	    } while (haveRand[randNum] == 1);

        haveRand[randNum] = 1;
	    rndElmt[i] = randNum;
    }

	for (int current = 0; current < DECK; current++)
	{
        sDeck[current] = oDeck[(rndElmt[current])];

//printf("position: %2d, card value: %2d\n", current, sDeck[current]);
    }

    return;
}
//---------------------------------------------------------------------------------------------
//
void dealDeck (int sDeck[], int dealt[HAND][NUMPLAYERS])
{
    int suit;
    int rank;
    int i = 0;      //current card in deck counter
    int x = 0;      //used only as lvalue for following ternary statements

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
            }

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
                default : printf("\a\nERROR\n");
                          break;
            }
        }
        printf("\n");
        getchar();
    }

    return;
}
//---------------------------------------------------------------------------------------------
//
void printHands (int dealt[NUMPLAYERS][HAND])
{
    int suit;
    int rank;
    int x = 0;          //used only as lvalue for following ternary statements

    for (int j = 0; j < NUMPLAYERS; j++)
    {
        printf("Player %d - ", j + 1);
        (j == 0) ? printf("North: \n") : x++;
        (j == 1) ? printf("East:  \n") : x++;
        (j == 2) ? printf("South: \n") : x++;
        (j == 3) ? printf("West:  \n") : x++;
        printf("------------------\n");

        for (int k = 0; k < HAND; k++)
        {

            if (k != 0)
            {
                printf("\n");   //no new line on first iteration
            }

            rank = (dealt[j][k] % 13) + 1;

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
            }

            (dealt[j][k] >= CMIN && dealt[j][k] <= CMAX) ? suit = 1 : x++;  //clubs
            (dealt[j][k] >= DMIN && dealt[j][k] <= DMAX) ? suit = 2 : x++;  //diamonds
            (dealt[j][k] >= HMIN && dealt[j][k] <= HMAX) ? suit = 3 : x++;  //hearts
            (dealt[j][k] >= SMIN && dealt[j][k] <= SMAX) ? suit = 4 : x++;  //spades

            switch (suit)
            {
                case 1  : printf("%c", CLUB);
                          break;
                case 2  : printf("%c", DIAMOND);
                          break;
                case 3  : printf("%c", HEART);
                          break;
                case 4  : printf("%c", SPADE);
                          break;
                default : printf("ERROR");
                          break;
            }
        }

        printf("\n------------------\n\n");
        getchar();
    }

    return;
}
