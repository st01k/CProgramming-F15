/*	Count number of words in file. Words are separated by 
	whitespace characters: space, tab, and newline.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define WHT_SPC\
         (cur == ' ' || cur == '\n' || cur == '\t')

int main (void)
{
//Local Declarations 
	int   cur;
	int   countWd = 0;
	char  word = 'O';       // O out of word: I in word 
	FILE* sp1;

//	Statements 
	if (!(sp1 = fopen("P07-07.DAT", "r")))
	   {
	    printf("Error opening P07-07.DAT for reading");
	    return (1);
	   } // if file open error 
	while ((cur = fgetc(sp1)) != EOF)
	   {
	    if (WHT_SPC)
	        word = 'O';
	    else
	        if (word == 'O')
	           {
	            countWd++;
	            word = 'I';
	           } // else 
	   } // while 
	printf("The number of words is: %d\n", countWd);

	fclose(sp1);
	return 0;
}	// main 

/*	Results:
The number of words is: 15

Input:
Now is the time for all good students
To come to the aid of their college.
*/