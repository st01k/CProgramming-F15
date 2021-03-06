/*
*****************************************************************************************************************
*                                       Name:            Array Sort & Search                                    *
*                                       Version:         3.1                                                    *
*                                       Chapter:         8, Assignment (p. 554, #54) & Extra Credit             *
*                                       Author:          Casey Murphy                                           *
*                                       Date Created:    13 Oct 15                                              *
*                                       Last Modified:   22 Oct 15                                              *
* ------------------------------------------------------------------------------------------------------------- *
* Generates a random array and a nearly ordered array to be sorted via selection, bubble, and insertion sorts.  *
* Each sort also counts the number of comparisons and moves.  A report is generated to 'SortComparison.txt'     *
* with sorted data and heuristic data in the users working directory.                                           *
*                                                                                                               *
* BONUS:  Linear and Binary searches implemented with heuristics data.  For array size modification change the  *
*         ARY_SIZE defined constant.  The random number selection sorted array is the input data for search.    *
*                                                                                                               *
* Extra:  I modified both searches to display all occurrences of the search parameter with a match count.       *
*****************************************************************************************************************
* Analysis:  Because of the way that a binary search operates, by splitting the search pool in half with each   *
*            pass, it is a much more efficient method than the linear (or sequential) search.  With every       *
*            linear search performed the program had to run through each element once, so the more the data     *
*            pool grows the more the processor has to work to complete the task.  Using the binary search       *
*            allows for the complexity to be reduced logarithmically with each pass.  The file I used to        *
*            analyze this data is called 'analyze.txt' and was attached with my first upload.                   *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>               //for srand in random number generation
#include <stdbool.h>            //for flag
#include <unistd.h>             //for dup2 to redirect output to file
#include <windows.h>            //for sleep
#include <fcntl.h>              //for open file
#include <ctype.h>              //for tolower

#define ARY_SIZE 50             //amount of numbers to sort
#define ARY_MIN  1              //min array limit
#define ARY_MAX  1000           //max array limit
#define LN_SIZE  10             //for report generation
#define NTH      10             //for nearly ordered array: every NTH number is modified
#define MOD      - 5            //for nearly ordered array: modifier on NTH digit

//function prototypes
void populateRandAry    (int* rAryPtr);
void populateNOrdAry    (int* nAryPtr);

void selectionSort      (int aryHold[], int last, bool flag, int moves, int comparisons, int sAry[]);
void bubbleSort         (int aryHold[], int last, bool flag, int moves, int comparisons);
void insertionSort      (int aryHold[], int last, bool flag, int moves, int comparisons);

void formFeed           (void);
void sleepEffect        (void);
void printSeparator     (void);
void printFlag          (bool flag);
void printArray         (int element, int cur);
void printHeuristics    (int moves, int comparisons);
void printToFile        (int rAry[], int nAry[], bool flag, int moves, int comparisons, int sAry[]);

void searchAry          (int searchHolder[], int comparisons);
int  linearSearch       (int numbers[], int key, int matches[], int* cPtr);
int  binarySearch       (int numbers[], int key, int matches[], int* cPtr);
//--------------------------------------------------------------------------------------
// main
int main()
{
    int     randAry[ARY_SIZE];      //random array
    int     nOrdAry[ARY_SIZE];      //nearly ordered array
    int     sortdAry[ARY_SIZE];     //sorted array passed for search option
    int     searchHolder[ARY_SIZE]; //array holder for search subfunctions
    int     moves;                  //heuristics data variable
    int     comparisons;            //heuristics data variable
    bool    flag;                   //true is random list, false is nearly ordered list

    printf("\n\n     Press Enter to populate the first array\n");
    printf("     with %d randomly generated numbers...\n", ARY_SIZE);
    getchar();
    sleepEffect();
    populateRandAry(randAry);

    printf("\n\n     Press Enter to populate the second array\n");
    printf("     with %d nearly ordered numbers...\n", ARY_SIZE);
    getchar();
    sleepEffect();
    populateNOrdAry(nOrdAry);

    puts("\n\nPress Enter to perform a selection sort on both arrays...");
    getchar();
    sleepEffect();
    selectionSort(randAry, ARY_SIZE - 1, true, moves, comparisons, sortdAry);

    //fills the array that is passed to search function
    for (int i = 0; i < ARY_SIZE; i++)
        searchHolder[i] = sortdAry[i];

    sleepEffect();
    selectionSort(nOrdAry, ARY_SIZE - 1, false, moves, comparisons, sortdAry);

    puts("\n\nPress Enter to perform a bubble sort on both arrays...");
    getchar();
    sleepEffect();
    bubbleSort(randAry, ARY_SIZE - 1, true, moves, comparisons);
    sleepEffect();
    bubbleSort(nOrdAry, ARY_SIZE - 1, false, moves, comparisons);

    puts("\n\nPress Enter to perform an insertion sort on both arrays...");
    getchar();
    sleepEffect();
    insertionSort(randAry, ARY_SIZE - 1, true, moves, comparisons);
    sleepEffect();
    insertionSort(nOrdAry, ARY_SIZE - 1, false, moves, comparisons);
    puts("");
    puts("");
    puts("Press Enter to continue...");
    getchar();

    searchAry(searchHolder, comparisons);
    getchar();
    formFeed();

    puts("\a\n\n===================================================================");
    puts("   Press enter to generate a report with ONLY the array data...");
    puts("===================================================================");
    getchar();

    printToFile(randAry, nOrdAry, flag, moves, comparisons, sortdAry);
    Sleep(864);

    return 0;
} // end main
//--------------------------------------------------------------------------------------
// populates and prints the random array
void populateRandAry (int* rAryPtr)
{
    puts("\n\nUnsorted Random Numbers: ");
    printSeparator();

    srand (time(NULL));
    for (int i = 0; i < ARY_SIZE; i++)
    {
        rAryPtr[i] = (rand() % ARY_MAX) + ARY_MIN;
        printArray(rAryPtr[i], i);
    }

    return;
}
//--------------------------------------------------------------------------------------
// populates and prints the nearly ordered array
void populateNOrdAry (int* nAryPtr)
{
    puts("\n\nUnsorted Nearly Ordered Numbers: ");
    printSeparator();

    for (int i = 0; i < ARY_SIZE; i++)
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
void selectionSort (int aryHold[], int last, bool flag, int moves, int comparisons, int sAry[])
{
    int smallest;
    int tempHolder;
    int i;
    int x;
    int ary[ARY_SIZE];

    for (x = 0; x <= last; x++)             //copies unsorted aryHold to ary
        ary[x] = aryHold[x];

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
        {
            printArray(ary[i], i);
            sAry[i] = ary[i];
        }

    printHeuristics(moves, comparisons);

    return;
}
//--------------------------------------------------------------------------------------
// sorts by bubble and prints both arrays
void bubbleSort (int aryHold[], int last, bool flag, int moves, int comparisons)
{
    int tempHolder;
    int i;
    int x;
    int ary[ARY_SIZE];

    for (x = 0; x <= last; x++)             //copies unsorted aryHold to ary
        ary[x] = aryHold[x];

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
void insertionSort (int aryHold[], int last, bool flag, int moves, int comparisons)
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
// subfunction called to print an array by element with LN_SIZE columns
void printArray (int element, int cur)
{
    (!((cur + 1) % LN_SIZE)) ? printf("%4d\n", element) : printf("%4d ", element);

    return;
}
//--------------------------------------------------------------------------------------
// subfunction called in each sort to announce which array type is being printed
void printFlag (bool flag)
{
    (flag) ? printf("Random") : printf("Nearly Ordered");

    return;
}
//--------------------------------------------------------------------------------------
// subfunction called to print heuristic results, sorts and searches
void printHeuristics (int moves, int comparisons)
{
    printf("\nMoves: %6d\t\t      Comparisons: %6d\n", moves, comparisons);

    return;
}
//--------------------------------------------------------------------------------------
// formatting spacer
void printSeparator (void)
{
    puts("-------------------------------------------------");

    return;
}
//--------------------------------------------------------------------------------------
// prints data to file SelectionSort.txt
void printToFile (int rAry[], int nAry[], bool flag, int moves, int comparisons, int sAry[])
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
        printArray(rAry[i], i);

    puts("\n\nUnsorted Nearly Ordered Numbers: ");
    printSeparator();
    for (i = 0; i < ARY_SIZE; i++)
        printArray(nAry[i], i);

    selectionSort(rAry, ARY_SIZE - 1, true, moves, comparisons, sAry);
    selectionSort(nAry, ARY_SIZE - 1, false, moves, comparisons, sAry);

    bubbleSort(rAry, ARY_SIZE - 1, true, moves, comparisons);
    bubbleSort(nAry, ARY_SIZE - 1, false, moves, comparisons);

    insertionSort(rAry, ARY_SIZE - 1, true, moves, comparisons);
    insertionSort(nAry, ARY_SIZE - 1, false, moves, comparisons);

    close(spReport);

    return;
}
//--------------------------------------------------------------------------------------
// prints a page full of new lines - form feed
void formFeed (void)
{
    for (int i = 0; i < 39; i++)
        puts("");

    return;
}
//--------------------------------------------------------------------------------------
// prints timed dots for wait transition
void sleepEffect (void)
{

    for (int i = 0; i < 25; i++)
    {
        Sleep(36);
        printf(". ");
    }

    Sleep(64);

    return;
}
//-----------------------------------------------------------------------------------------
// interface for search, calls linear and binary searches, prints search results to screen
void searchAry (int sHolder[], int comparisons)
{
    char input;
    char again;
//---------------------------------search option, user input
    formFeed();
    puts("\n");
    printSeparator();
    puts("");
    printf("Would you like to perform a search (Y/N)?       ");
    input = getchar();
    puts("");
    tolower(input);

    switch (input)
    {
        case 'y' :  break;
        case 'n' :  return;
                    break;
        default  :  while (input != 'y' && input != 'n')
                    {
                        printf("\aInvalid Response. Re-enter your answer (Y/N): ");
                        scanf(" %c", &input);
                        if (input == 'n')
                            return;
                    }
    }
//---------------------------------prints array to search from
    printSeparator();
    puts("      Search the sorted random array below.");
    printSeparator();

    for (int i = 0; i < ARY_SIZE; i++)
        printArray(sHolder[i], i);

    printSeparator();
//---------------------------------search calls--------------------------------------
    int index;
    int key;

    int  lMatches[ARY_SIZE] = {0};
    int  bMatches[ARY_SIZE] = {0};

//---------------------------------linear call, prints results
    do
    {
        puts("\nLINEAR  -  In the order that matches are found.");
        printf("\nEnter search parameter: ");
        scanf("%d", &key);

        index = linearSearch(sHolder, key, lMatches, &comparisons);

        if (index > 0)
            {
                printf("\n%d matched %d @ index: ", index, key);
                for (int i = 0; i < index; i++)
                    printArray(lMatches[i], i);
            }
        else
            printf("\a\n\t\t   No Match.\n");

        printf("\n");
        printHeuristics(0, comparisons);
        printf("\n");
        printSeparator();
//---------------------------------binary call, prints results
        puts("\nBINARY  -  In the order that matches are found.");
        printf("\nEnter search parameter: ");
        scanf("%d", &key);

        index = binarySearch(sHolder, key, bMatches, &comparisons);

        if (index >= 0 )
            {
                printf("\n%d matched %d @ index: ", index, key);
                for (int i = 0; i < index; i++)
                    printArray(bMatches[i], i);
            }

        else
            printf("\a\n\t\t   No Match\n");

        printf("\n");
        printHeuristics(0, comparisons);
        printf("\n");
//---------------------------------reconfirm search option, user input
        printSeparator();
        printf("\nSearch again (Y/N)? ");
        scanf(" %c", &again);
        tolower(again);

        while (again != 'y' && again != 'n')
        {
            printf("\aInvalid Response. Re-enter your answer (Y/N): ");
            scanf(" %c", &again);
            if (again == 'n')
                return;
        }

    } while (again == 'y');
//---------------------------------search end interaction
    puts("");
    printSeparator();
    puts("\nPress Enter to continue...\n");
    getchar();

    return;
}
//--------------------------------------------------------------------------------------
// processes linear search
int linearSearch (int numbers[], int key, int matches[], int* cPtr)
{
    int arySz = 0;

    *cPtr = 0;

    for (int i = 0; i < ARY_SIZE; i++)
    {
        *cPtr += 1;                      //heuristics data calculation
        if (key == numbers[i])
            {
                matches[arySz] = i;
                arySz++;
            }
    }

    if (arySz <= 0)
        return -1;

    return arySz;
}
//--------------------------------------------------------------------------------------
// processes binary search
int binarySearch (int numbers[], int key, int matches[], int* cPtr)
{
    int l = 0;
    int u = ARY_SIZE - 1;
    int c;
    int mid;

    int flag = 0;
    int arySz = 0;

    *cPtr = 0;

    while (l <= u)
    {
        *cPtr += 1;                      //heuristics data calculation

        mid = (l + u) / 2;

         *cPtr += 1;                      //heuristics data calculation
         if (key == numbers[mid])
         {
             arySz++;
             matches[arySz - 1] = mid;

             for (int i = 1; i > 0; i++)
             {
                 *cPtr += 1;                      //heuristics data calculation
                 if (numbers[mid - i] == key)
                 {
                    arySz++;
                    matches[arySz - 1] = (mid - i);
                 }

                 *cPtr += 1;                      //heuristics data calculation
                 if (numbers[mid - i] != key)
                     flag = 1;

                 *cPtr += 1;                      //heuristics data calculation
                 if (numbers[mid + i] == key)
                 {
                     arySz++;
                     matches[arySz - 1] = (mid + i);
                 }

                 *cPtr += 1;                      //heuristics data calculation
                 if (flag == 1 && numbers[mid + i] != key)
                     i = -1;                      //exit trigger for loop
             }

             return arySz;
         }

         *cPtr += 1;                      //heuristics data calculation
         if (key < numbers[mid])
             u = mid - 1;

         *cPtr += 1;                      //heuristics data calculation
         if (key > numbers[mid])
             l = mid + 1;
    }
    return -1;
}
