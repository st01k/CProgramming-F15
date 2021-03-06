/*
*****************************************************************************************************************
*                                       Name:            Array Sort                                             *
*                                       Version:         1.0                                                    *
*                                       Chapter:         8, Assignment (p. 554, #54)                            *
*                                       Author:          Casey Murphy                                           *
*                                       Date Created:    13 Oct 15                                              *
*                                       Last Modified:   16 Oct 15                                              *
* ------------------------------------------------------------------------------------------------------------- *
* Generates a random array and a nearly ordered array to be sorted via selection, bubble, and insertion sorts.  *
* Each sort also counts the number of comparisons and moves.  A report is generated to 'SortComparison.txt'     *
* with sorted data and heuristic data.                                                                          *
*****************************************************************************************************************
* Analysis: Because of the logical methodology used in the selection and bubble sorts, each have the same amount*
*           of comparisons.  The insertion sort produced significantly less comparisons, especially when fed a  *
*           nearly ordered list as opposed to random numbers.                                                   *
*           The bubble and insertion sorts had the same amount of moves, but differing values in comparisons,   *
*           leaving the selection sort with far fewer moves than either of its counterparts.  Again, when the   *
*           data is nearly ordered there are significantly less transactions that take place.                   *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>               //for srand in random number generation
#include <stdbool.h>            //for flag
#include <unistd.h>             //for dup2 to redirect output
#include <windows.h>            //for sleep
#include <fcntl.h>              //for open file

#define ARY_SIZE 50             //amount of numbers to sort
#define ARY_MIN  1              //min array limit
#define ARY_MAX  1000           //max array limit
#define LN_SIZE  10             //for report generation
#define NTH      10             //for nearly ordered array: every NTH number is modified
#define MOD      - 5            //for nearly ordered array: modifier on NTH digit

//function prototypes
void populateRandAry    (int* rAryPtr);
void populateNOrdAry    (int* nAryPtr);
void selectionSort      (int aryHold[], int last, bool flag, int moves, int comparisons);
void bubbleSort         (int aryHold[], int last, bool flag, int moves, int comparisons);
void insertionSort      (int aryHold[], int last, bool flag, int moves, int comparisons);

void printArray         (int element, int cur);
void printFlag          (bool flag);
void printHeuristics    (int moves, int comparisons);
void printSeparator     (void);
void printToFile        (int rAry[], int nAry[], bool flag, int moves, int comparisons);

void sleepEffect        (void);

int main()
{
    int     randAry[ARY_SIZE];  //random array
    int     nOrdAry[ARY_SIZE];  //nearly ordered array
    int     moves;              //heuristics data variable
    int     comparisons;        //heuristics data variable
    bool    flag;               //true is random list, false is nearly ordered list

        puts("\n\nPress Enter to populate the first array with random numbers...");
        getchar();
        sleepEffect();
        populateRandAry(randAry);

        puts("\n\nPress Enter to populate the second array with a nearly ordered list...");
        getchar();
        sleepEffect();
        populateNOrdAry(nOrdAry);

        puts("\n\nPress Enter to perform a selection sort on both arrays...");
        getchar();
        sleepEffect();
        flag = true;
        selectionSort(randAry, ARY_SIZE - 1, flag, moves, comparisons);
        sleepEffect();
        flag = false;
        selectionSort(nOrdAry, ARY_SIZE - 1, flag, moves, comparisons);

        puts("\n\nPress Enter to perform a bubble sort on both arrays...");
        getchar();
        sleepEffect();
        flag = true;
        bubbleSort(randAry, ARY_SIZE - 1, flag, moves, comparisons);
        sleepEffect();
        flag = false;
        bubbleSort(nOrdAry, ARY_SIZE - 1, flag, moves, comparisons);

        puts("\n\nPress Enter to perform an insertion sort on both arrays...");
        getchar();
        sleepEffect();
        flag = true;
        insertionSort(randAry, ARY_SIZE - 1, flag, moves, comparisons);
        sleepEffect();
        flag = false;
        insertionSort(nOrdAry, ARY_SIZE - 1, flag, moves, comparisons);

        puts("\n\n===================================================================");
        puts("\tPress enter to generate a report with this data...");
        puts("===================================================================");
        getchar();

        printToFile(randAry, nOrdAry, flag, moves, comparisons);
        Sleep(864);

    return 0;
} // end main

//--------------------------------------------------------------------------------------
// populates and prints the random array
void populateRandAry (int* rAryPtr)
{
    int i;

    puts("\n\nUnsorted Random Numbers: ");
    printSeparator();

    srand (time(NULL));
    for (i = 0; i < ARY_SIZE; i++)
    {
        rAryPtr[i] = (rand() % ARY_MAX) + ARY_MIN;
        printArray(rAryPtr[i], i);
    }

    return;
}
//--------------------------------------------------------------------------------------
// populates and prints the nearly ordered array
void populateNOrdAry(int* nAryPtr)
{
    int i;

    puts("\n\nUnsorted Nearly Ordered Numbers: ");
    printSeparator();

    for (i = 0; i < ARY_SIZE; i++)
    {
        nAryPtr[i] = i;

        if (!i)                             //skips 0 in modification
            ;
        else if (!(i % NTH))
            nAryPtr[i] = i MOD;             //assigns all NTH values to MODified value

        printArray(nAryPtr[i], i);
    }

    return;
}
//--------------------------------------------------------------------------------------
// sorts by selection and prints both arrays
void selectionSort(int aryHold[], int last, bool flag, int moves, int comparisons)
{
    int smallest;
    int tempHolder;
    int i;
    int x;
    int ary[ARY_SIZE];

    for (x = 0; x <= last; x++)             //copies unsorted aryHold to ary
    {
        ary[x] = aryHold[x];
    }

    moves       = 0;
    comparisons = 0;

    for (int cur = 0; cur < last; cur++)
    {
        smallest = cur;

        for (int step = cur + 1; step <= last; step++)
        {
            comparisons += 1;               //heuristics data calculation
            if (ary[step] < ary[smallest])
            {
                smallest = step;
                moves += 1;                 //heuristics data calculation
            }//end if
        }//end inner for

        tempHolder = ary[cur];
        ary[cur] = ary[smallest];
        moves += 1;                         //heuristics data calculation
        ary[smallest] = tempHolder;
    }//end for

    printf("\n\nSelection Sorted ");
    printFlag(flag);
    printf(" Numbers: \n");
    printSeparator();

    for (i = 0; i < ARY_SIZE; i++)
        printArray(ary[i], i);

    printHeuristics(moves, comparisons);

    return;
}
//--------------------------------------------------------------------------------------
// sorts by bubble and prints both arrays
void bubbleSort(int aryHold[], int last, bool flag, int moves, int comparisons)
{
    int tempHolder;
    int i;
    int x;
    int ary[ARY_SIZE];

    for (x = 0; x <= last; x++)             //copies unsorted aryHold to ary
    {
        ary[x] = aryHold[x];
    }

    moves       = 0;
    comparisons = 0;

    for (int cur = 0; cur < last; cur++)
    {
        for (int step = last; step > cur; step--)
        {
            comparisons += 1;               //heuristics data calculation
            if (ary[step] < ary[step - 1])
            {
                tempHolder = ary[step];
                ary[step] = ary[step - 1];
                moves += 1;                 //heuristics data calculation
                ary[step - 1] = tempHolder;
            }//end if
        }//end inner for
    }

    printf("\n\nBubble Sorted ");
    printFlag(flag);
    printf(" Numbers: \n");
    printSeparator();

    for (i = 0; i < ARY_SIZE; i++)
        printArray(ary[i], i);

    printHeuristics(moves, comparisons);

    return;
}
//--------------------------------------------------------------------------------------
// sorts by insertion and prints both arrays
void insertionSort(int aryHold[], int last, bool flag, int moves, int comparisons)
{
    int step;
    int tempHolder;
    bool located;
    int i;
    int x;
    int ary[ARY_SIZE];

    for (x = 0; x <= last; x++)             //copies unsorted aryHold to ary
    {
        ary[x] = aryHold[x];
    }

    moves       = 0;
    comparisons = 0;

    for (int cur = 0; cur <= last; cur++)
    {
        located = false;
        tempHolder = ary[cur];

        for (step = cur - 1; step >= 0 && !located;)
        {
            comparisons += 1;               //heuristics data calculation
            if (tempHolder < ary[step])
            {
                ary[step + 1] = ary[step];
                moves += 1;                 //heuristics data calculation
                step--;
            }//end if
            else
                located = true;
        }//end inner for

        ary[step + 1] = tempHolder;
    }//end for

    printf("\n\nInsertion Sorted ");
    printFlag(flag);
    printf(" Numbers: \n");
    printSeparator();

    for (i = 0; i < ARY_SIZE; i++)
        printArray(ary[i], i);

    printHeuristics(moves, comparisons);

    return;
}
//--------------------------------------------------------------------------------------
// subfunction called in each sort to print per element
void printArray(int element, int cur)
{
        if (!((cur + 1) % LN_SIZE))
            printf("%4d\n", element);
        else
            printf("%4d ", element);

    return;
}
//--------------------------------------------------------------------------------------
// subfunction called in each sort to print which array is current
void printFlag(bool flag)
{
    if (flag)
        printf("Random");
    else
        printf("Nearly Ordered");

    return;
}
//--------------------------------------------------------------------------------------
// subfunction called in each sort to print heuristic results
void printHeuristics(int moves, int comparisons)
{
    printf("\nMoves: %5d\t\t       Comparisons: %5d\n", moves, comparisons);

    return;
}
//--------------------------------------------------------------------------------------
// formatting spacer
void printSeparator(void)
{
    puts("-------------------------------------------------");

    return;
}
//--------------------------------------------------------------------------------------
// prints data to file SelectionSort.txt
void printToFile (int rAry[], int nAry[], bool flag, int moves, int comparisons)
{
    int i;

    int spReport = open("SortComparison.txt", O_RDWR | O_TRUNC | O_CREAT);
    if (spReport < 0)
        {
            printf("\a");
            puts("Error creating file.  \n");
            puts("SortComparison.txt may already exist.\n");
            puts("If so, delete it to generate a new report.\n");
            exit (1);
        } // if file open error

    puts("This data is being written to the file 'SortComparison.txt' in");
    puts("\t\t   your current working directory.\n");
    puts("===================================================================");

    dup2(spReport, 1);

    puts("\nUnsorted Random Numbers: ");
    printSeparator();
    for (i = 0; i < ARY_SIZE; i++)
    {
        printArray(rAry[i], i);
    }

    puts("\n\nUnsorted Nearly Ordered Numbers: ");
    printSeparator();
    for (i = 0; i < ARY_SIZE; i++)
    {
        printArray(nAry[i], i);
    }

    flag = true;
    selectionSort(rAry, ARY_SIZE - 1, flag, moves, comparisons);
    flag = false;
    selectionSort(nAry, ARY_SIZE - 1, flag, moves, comparisons);

    flag = true;
    bubbleSort(rAry, ARY_SIZE - 1, flag, moves, comparisons);
    flag = false;
    bubbleSort(nAry, ARY_SIZE - 1, flag, moves, comparisons);

    flag = true;
    insertionSort(rAry, ARY_SIZE - 1, flag, moves, comparisons);
    flag = false;
    insertionSort(nAry, ARY_SIZE - 1, flag, moves, comparisons);

    close(spReport);

    return;
}
//--------------------------------------------------------------------------------------
// timed dots for wait transition
void sleepEffect        (void)
{

    for (int i = 0; i < 25; i++)
    {
        Sleep(36);
        printf(". ");
    }

    Sleep(64);

    return;
}
