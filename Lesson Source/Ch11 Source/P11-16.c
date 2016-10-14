/*	Demonstrate memory formatting. 
	   Written by: 
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations
	char  strng[80] = "Einstein, Albert; 1234 97 A";
	char  strngOut[80];
	char  name[50];
	char  id[5];
	int   score;
	char  grade;
	
//	Statements
	printf("String contains:  \"%s\"\n", strng);
	
	sscanf(strng, "%49[^;] %*c %4s %d %c",
	       name, id, &score, &grade);

	printf("Reformatted data: \n");
	printf("   Name:          \"%s\"\n", name);
	printf("   id:            \"%s\"\n", id);
	printf("   score:          %d\n", score);
	printf("   grade:          %c\n", grade);
	
	sprintf(strngOut, "%s %4s %3d %c", 
            name, id, score, grade);	
    printf("New string:       \"%s\"\n", strngOut);
	return 0;
}	// main

/*	Results:
String contains:  "Einstein, Albert; 1234 97 A"
Reformatted data: 
   Name:          "Einstein, Albert"
   id:            "1234"
   score:          97
   grade:          A
New string:       "Einstein, Albert 1234  97 A"
*/