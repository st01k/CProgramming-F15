/* This program creates a text file. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void)
{
//	Local Declarations 
	FILE* spText;
	int   c;
	int   closeStatus;

//	Statements 
	printf("This program copies input to a file.\n");
	printf("When you are through, enter <EOF>.\n\n");
	
	if (!(spText = fopen("P07-07.DAT","w")))
	   {
	    printf("Error opening P07-07.DAT for writing");
	    return (1);
	   } // if open 

	while ((c = getchar()) != EOF)
	   fputc(c, spText);

	closeStatus = fclose(spText);
	if (closeStatus == EOF)
	   {
	    printf("Error closing file\a\n");
	    return 100;
	   } // if 
	
	printf("\n\nYour file is complete\n");
	return 0;
}	// main 

/*	Results:
This program copies input to a file.
When you are through, enter <EOF>.

Now is the time for all good students
To come to the aid of their college.^d

Your file is complete
*/