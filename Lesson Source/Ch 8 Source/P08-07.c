/*	Read data from a file into an array. 
	Build frequency array & print data in histogram.
	   Written by: 
	   Data: 
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELMNTS 100
#define ANLYS_RNG 20

//	Function Declarations 
	int getData (int numbers[], int size, int range);

	void printData     (int numbers[],  
	                    int size,        int lineSize);
	void makeFrequency (int numbers[],   int size,
	                    int frequency[], int range);
	void makeHistogram (int frequency[], int range);

int main (void)
{
//	Local Declarations 
	int size;
	int nums      [MAX_ELMNTS];
	int frequency [ANLYS_RNG];

//	Statements 
	size = getData (nums, MAX_ELMNTS, ANLYS_RNG);
	printData (nums, size, 10);

	makeFrequency(nums, size, frequency, ANLYS_RNG);
	makeHistogram(frequency, ANLYS_RNG);
	return 0;
}	// main 

/*	==================== getData ====================
	Read data from file into array. The array 
	does not have to be completely filled.
	   Pre   data is an empty array 
	         size is maximum elements in array 
	         range is highest value allowed 
	   Post  array is filled. Return number of elements 
*/
int getData (int data [], int size, int range)
{
//	Local Declarations 
	int   dataIn;
	int   loader = 0;
	FILE* fpData;

//	Statements 
// Adjust range for zero value 
	range--;
	if (!(fpData = fopen ("P08-07.dat", "r")))
	   printf("Error opening file\a\a\n") , exit (100); 

	while (loader < size 
	    && fscanf(fpData, "%d", &dataIn) != EOF)
	   if (dataIn >= 0 && dataIn <= range)
	       data[loader++] = dataIn;
	   else
	       printf("\nData point %d invalid. Ignored. \n",
	              dataIn);

//	Test to see what stopped while 
	if (loader == size)
	    printf("\nToo much data. Process what read.\n");
	return loader;
}	// getData 

/*	==================== printData ====================
	Prints the data as a two-dimensional array.
	   Pre   data: a filled array
	         size: number of elements in array
	         lineSize: number of elements printed/line
	   Post  the data have been printed
*/
void printData (int data[], int size, int lineSize)
{
//	Local Declarations 
	int numPrinted = 0;

//	Statements 
	printf("\n\n");
	for (int i = 0; i < size; i++)
	   {
	    numPrinted++;
	    printf("%2d ", data[i]);
	    if (numPrinted >= lineSize)
	       {
	        printf("\n");
	        numPrinted = 0;
	       } // if 
	   } // for 
	printf("\n\n");
	return;
}	// printData 

/*	================= makeFrequency ==================
	analyze the data in nums and build their frequency
	distribution
	   Pre   nums: array of validated data to be analyzed 
	         last: number of elements in array 
	         frequency: array for accumulation.
	         range: maximum index/value for frequency
	   Post  Frequency array has been built.
*/ 
void makeFrequency (int nums[],      int last, 
                    int frequency[], int range) 
{
// Statements 
	// First initialize the frequency array 
	for (int f = 0; f < range; f++)
	     frequency [f] = 0;

	// Scan numbers and build frequency array 
	for (int i = 0; i < last; i++)
	     frequency [nums [i]]++;
	return;
}	// makeFrequency 

/*	================= makeHistogram ==================
	Print a histogram representing analyzed data. 
	   Pre   freq contains times each value occurred 
	         size represents elements in frequency array
	   Post  histogram has been printed
*/
void makeHistogram (int freq[], int range)
{
//	Statements 
	for (int i = 0; i < range; i++)
	   {
	    printf ("%2d %2d ", i, freq[i]);
	    for (int j = 1; j <= freq[i]; j++)
	         printf ("*");
	    printf ("\n");
	   } // for i... 
	return;
}	// makeHistogram 
//	================= End of Program ================= 

/*	Results:
Data point 20 invalid. Ignored. 

Data point 25 invalid. Ignored.

 1  2  3  4  5  6  7  8  7 10
 2 12 13 13 15 16 17 18 17  7
 3  4  6  8 10  2  4  6  8 10
 4  3  5  7  1  3  7  7 11 13
 5 10 11 12 13 16 18 11 12  7
 6  1  2  2  3  3  3  4  4  4
 7  7  8  7  6  5  4  1  2  2
 8 11 11 13 13 13 17 17  7  7
13 17 17 15 15

 0  0
 1  4 ****
 2  7 *******
 3  7 *******
 4  8 ********
 5  4 ****
 6  5 *****
 7 12 ************
 8  5 *****
 9  0
10  4 ****
11  5 *****
12  3 ***
13  8 ********
14  0
15  3 ***
16  2 **
17  6 ******
18  2 **
19  0
*/