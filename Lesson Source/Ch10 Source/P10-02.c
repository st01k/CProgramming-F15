/*	Test driver for binary Search
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_ARY_SIZE 12

//	Prototype Declarations 
int binarySearch (int list[], int*  endPtr, int target, int** locnPtr);

int main (void) 
{
//	Local Declarations 
	int* locn;
	int  target;
	int	 ary[MAX_ARY_SIZE] = {  4,  7,  8, 10, 
	                           14, 21, 22, 36, 
	                           62, 77, 81, 91, };
//	Statements 
	printf("Data: ");
	for (int i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[i]);
	
	printf("\n\nEnter a key for search     : ");
	scanf("%d", &target);	
	do
	  {
	   if (binarySearch (ary, &(ary[MAX_ARY_SIZE - 1]), target, &locn))
	       printf("%3d found at location:       %2d\n", target, *locn);
	   else
	       printf("%3d NOT found at locn:       %2d\n", target, *locn);
	   printf("Enter next key <-1> to quit: ");
	   scanf("%d", &target);	
	  } while (target != -1);

	printf("End of search.\n");
	return 0;
}	// main 

/* ==================== binary Search ====================
	Search an ordered list using Binary Search 
	   Pre   list must contain at least one element
	         endPtr is pointer to largest element in list
	         target is value of element being sought
	   Post  FOUND: locnPtr pointer to target element 
	                return 1 (found)
	         !FOUND: locnPtr = element below or above target 
	                 return 0 (not found)
*/
int binarySearch (int list[], int*  endPtr,
                  int target, int** locnPtr)
{
//	Local Declarations 
	int* firstPtr;
	int* midPtr;
	int* lastPtr;

//	Statements
	firstPtr = list;
	lastPtr  = endPtr;
	while (firstPtr <= lastPtr)
	   {
	    midPtr = firstPtr + (lastPtr - firstPtr) / 2;
	    if (target > *midPtr)
	       // look in upper half
	       firstPtr = midPtr + 1;
	    else if (target < *midPtr)
	       // look in lower half
	       lastPtr = midPtr - 1;
	    else
	       // found equal: force exit
	       firstPtr = lastPtr + 1;
	   } // end while
	*locnPtr = midPtr;
	return (target == *midPtr);
}	// binarySearch

/*	Results:
Data:   4  7  8 10 14 21 22 36 62 77 81 91

Enter a key for search     : 89
 89 NOT found at locn:       91
Enter next key <-1> to quit: 61
 61 NOT found at locn:       36
Enter next key <-1> to quit: 4
  4 found at location:        4
Enter next key <-1> to quit: 22
 22 found at location:       22
Enter next key <-1> to quit: 91
 91 found at location:       91
Enter next key <-1> to quit: -1
End of search.
*/
