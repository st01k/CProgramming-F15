/*	Demonstrate pointers with Selection Sort
	   Written by: 
	   Date written: 
*/
#include <stdio.h>
#define SIZE 25

//	Function Declarations
int*  getData    (int* pAry,    int  arySize);
void  selectSort (int* pAry,    int* last);
void  printData  (int* pAry,    int* last);
int*  smallest   (int* pAry,    int* pLast); 
void  exchange   (int* current, int* smallest);

int main (void)
{
//	Local Declarations
	int  ary[SIZE];
	int* pLast;

//	Statements
	pLast = getData (ary, SIZE);
	selectSort (ary, pLast);
	printData  (ary, pLast);
	return 0;
}	// main

/*	==================== getData ====================
	Reads data from keyboard into array for sorting.
	   Pre   pAry is pointer to array to be filled 
	         arySize is integer with maximum array size
	   Post  array filled. Returns address of last element 
*/
int* getData (int* pAry, int arySize)
{
//	Local Declarations 
	int  ioResult;
	int  readCnt = 0;
	int* pFill   = pAry;

//	Statements
	do
	   {
	    printf("Please enter number or <EOF>: ");
	    ioResult = scanf("%d", pFill);
	    if (ioResult == 1)
	       {
	        pFill++;
	        readCnt++;
	       } // if
	   } while (ioResult == 1 && readCnt < arySize);

	printf("\n\n%d numbers read.", readCnt);
	return (--pFill);
}	// getData

/*	==================== selectSort ====================
	Sorts by selecting smallest element in unsorted  
	portion of the array and exchanging it with element 
	at the beginning of the unsorted list.
	   Pre   array must contain at least one item 
	         pLast is pointer to last element in array
	   Post  array rearranged smallest to largest
*/
void selectSort (int* pAry,  int* pLast)
{
//	Local Declarations
	int* pWalker; 
	int* pSmallest; 

//	Statements 
	for (pWalker = pAry; pWalker < pLast; pWalker++) 
	    {
	     pSmallest = smallest (pWalker, pLast);
	     exchange (pWalker, pSmallest);
	    } // for
	return;
}	// selectSort

/*	==================== smallest ====================
	Find smallest element starting at current pointer.
	   Pre   pAry points to first unsorted element
	   Post  smallest element identified and returned 
*/
int* smallest (int* pAry, int* pLast)
{
//	Local Declarations 
	int* pLooker;
	int* pSmallest;

//	Statements
	for (pSmallest = pAry, pLooker = pAry + 1;
	     pLooker <= pLast;
	     pLooker++)
	   if (*pLooker < *pSmallest) 
	        pSmallest = pLooker;
	return pSmallest;
}	// smallest

/*	====================== exchange ====================
	Given pointers to two array elements, exchange them
	   Pre   p1 & p2 are pointers to exchange values
	   Post  exchange is completed
*/
void exchange (int* p1, int* p2)
{
//	Local Declarations
	int temp;
	
//	Statements 
	temp  =  *p1;
	*p1   =  *p2;
	*p2   =  temp;
	return;
}	// exchange

/*	==================== printData ====================
	Given a pointer to an array, print the data.
	   Pre   pAry points to array to be filled
	         pLast identifies last element in the array
	   Post  data have been printed 
*/
void  printData (int* pAry, int* pLast)
{
//	Local Declarations
	int  nmbrPrt;
	int* pPrint;

//	Statements
	printf("\n\nYour data sorted are: \n");
	for (pPrint = pAry, nmbrPrt = 0;
	     pPrint <= pLast;
	     nmbrPrt++, pPrint++)
	   printf ("\n#%02d %4d", nmbrPrt, *pPrint);
	printf("\n\nEnd of List ");
	return;
}	// PrintData
//	================ End of Program =================

/*	Results
Please enter number or <EOF>: 31
Please enter number or <EOF>: 11
Please enter number or <EOF>: 43
Please enter number or <EOF>: 89
Please enter number or <EOF>: 77
Please enter number or <EOF>: 54
Please enter number or <EOF>: 65
Please enter number or <EOF>: 23
Please enter number or <EOF>: 54
Please enter number or <EOF>: ^d

9 numbers read.

Your data sorted are: 

#00   11
#01   23
#02   31
#03   43
#04   54
#05   54
#06   65
#07   77
#08   89

End of List 
*/