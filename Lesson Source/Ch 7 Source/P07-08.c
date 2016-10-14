/*	This program copies one text file into another.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
int main (void) 
{
//	Local Declarations 
	int   c;
	int   closeStatus;
	FILE* sp1;
	FILE* sp2;

//	Statements 
	printf("Begin file copy\n");

	if (!(sp1 = fopen ("P07-07.DAT", "r")))
		{
		 printf("Error opening P07-07.DAT for reading");
		 return (1);
		} // if open input 
	if (!(sp2 = fopen ("P07-08.DAT", "w")))
		{
		 printf("Error opening P07-08.DAT for writing");
		 return (2);
		} // if open output 

	while ((c = fgetc(sp1)) != EOF)
		fputc(c, sp2);

	fclose(sp1);
	closeStatus = fclose(sp2);
	if (closeStatus == EOF)
	   {
	    printf("File close error.\a\n");
	    return 201;
	   } // if close error 
	printf("File successfully created\n");
	return 0;
}	// main 

/*	Results:
Begin file copy
File successfully created

Output file contains:
Now is the time for all good students
To come to the aid of their college.
*/