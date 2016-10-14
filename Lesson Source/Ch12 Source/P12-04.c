/*	This program sorts an array of student structures
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_STU 5

//	Global Type Declaration
	typedef struct
	   {
	    char  name[26];
	    int   midterm[3];
	    int   final;
	   } STUDENT;

//	Function Declarations
void insertionSort (STUDENT list[], int last);

int main (void)
{
//	Local Declarations
	STUDENT  stuAry[NUM_STU] = 
	   {
	    {"Charles, George", {85, 94, 79}, 93},
	    {"Adams, Karin",    {75, 91, 89}, 89},
	    {"Nguyen, Tuan",    {87, 88, 89}, 90},
	    {"Oh, Bill",        {78, 96, 88}, 91},
	    {"Chavez, Maria",   {83, 79, 93}, 91}
	   } ; // stuAry

//	Statements
	printf("Unsorted data:\n");
	for (STUDENT* pStuPtr = stuAry; 
	              pStuPtr < stuAry + NUM_STU; 
	              pStuPtr++) 
	   printf("%-26s %4d %4d %4d %4d\n",
	           pStuPtr->name, 
	           pStuPtr->midterm[0],
	           pStuPtr->midterm[1],
	           pStuPtr->midterm[2],
	           pStuPtr->final);
	printf("\n");
 
	insertionSort (stuAry, NUM_STU - 1);
	 
	printf("Sorted data:\n");
	for (STUDENT* pStuPtr = stuAry; 
	              pStuPtr < stuAry + NUM_STU; 
	              pStuPtr++) 
	   printf("%-26s %4d %4d %4d %4d\n",
	           pStuPtr->name, 
	           pStuPtr->midterm[0],
	           pStuPtr->midterm[1],
	           pStuPtr->midterm[2],
	           pStuPtr->final);
	return 0;
}  // main

/*	================== insertionSort ================== 
	Sort list using Insertion Sort. The list is divided 
	into sorted and unsorted lists. With each pass, the
	first element in unsorted list is inserted into 
	sorted list.
	   Pre   list must contain at least one element 
	         last is index to last element in list
	   Post  list has been rearranged.
*/
void insertionSort (STUDENT  list[], int last)
{
//	Local Declarations
	bool     located;
	STUDENT  temp;
	STUDENT* pCurrent;
	STUDENT* pWalker;
	STUDENT* pLast;

//	Statements
	for (pCurrent = list + 1, pLast = list + last; 
	     pCurrent <= pLast; 
	     pCurrent++)
	  {
	   located =  false;
	   temp    = *pCurrent;
	
	   for  (pWalker  = pCurrent - 1;
	         pWalker >= list && !located; 
	        )
	      if (strcmp(temp.name, pWalker->name) < 0)
	         {
	          *(pWalker + 1) = *pWalker;
	          pWalker--;
	         } // if
	      else
	         located = true; 
	   *(pWalker + 1)  = temp;
	  } // for pCurrent
	return;
}	// insertionSort
//	================= End of Program =================

/*	Results:
Unsorted data:
Charles, George              85   94   79   93
Adams, Karin                 75   91   89   89
Nguyen, Tuan                 87   88   89   90
Oh, Bill                     78   96   88   91
Chavez, Maria                83   79   93   91

Sorted data:
Adams, Karin                 75   91   89   89
Charles, George              85   94   79   93
Chavez, Maria                83   79   93   91
Nguyen, Tuan                 87   88   89   90
Oh, Bill                     78   96   88   91
*/