/*	Test driver for searching. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_ARY_SIZE 12

//	Prototype Declarations 
bool binarySearch (int list[], int  end, int target, int* locn);

int main (void) 
{
//	Local Declarations 
	int i;
	int locn;
	int target;
	int	ary[MAX_ARY_SIZE] = {  4,  7,  8, 10, 
	                          14, 21, 22, 36, 
	                          62, 77, 81, 91, };
//	Statements 
	printf("Data: ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[i]);
	
	printf("\n\nEnter a key for search     : ");
	scanf("%d", &target);	
	do
	  {
	   if (binarySearch (ary, MAX_ARY_SIZE - 1, target, &locn))
	       printf("%3d found at location:       %2d\n", target, locn);
	   else
	       printf("%3d NOT found at locn:       %2d\n", target, locn);
	   printf("Enter next key <-1> to quit: ");
	   scanf("%d", &target);	
	  } while (target != -1);

	printf("End of search.\n");
	return 0;
}	// main 

/*	=================== binarySearch ===================
	Search an ordered list using Binary Search 
	   Pre   list must contain at least one element
	         end is index to the largest element in list
	         target is the value of element being sought
	         locn is address for located target index
	   Post  Found: locn = index to target element 
	                return 1 (found)
	         Not Found: locn = element below or above target 
	                    return 0 (not found)
*/
bool binarySearch (int list[], int  end,
                   int target, int* locn)
{
//	Local Declarations
	int first;
	int mid;
	int last;

//	Statements
	first = 0;
	last = end;
	while (first <= last)
	   {
	    mid = (first + last) / 2;
	    if (target > list[mid])
	       // look in upper half
	       first = mid + 1;
	    else if (target < list[mid])
	       // look in lower half
	       last = mid - 1;
	    else
	       // found equal: force exit
	       first = last + 1;
	   } // end while
	*locn = mid;
	return target == list [mid];
}	// binarySearch

/*	Results:
	Data:   4  7  8 10 14 21 22 36 62 77 81 91

	Enter a key for search     : 4
	  4 found at location:        0
	Enter next key <-1> to quit: 7
	  7 found at location:        1
	Enter next key <-1> to quit: 91
	 91 found at location:       11
	Enter next key <-1> to quit: 2
	2 NOT found at locn:          0
	Enter next key <-1> to quit: 22
	 22 found at location:        6
	Enter next key <-1> to quit: 92
	 91 found at location:       11
	Enter next key <-1> to quit: -1
	End of search.
*/
