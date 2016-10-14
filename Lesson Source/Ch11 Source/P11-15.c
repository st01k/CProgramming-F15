/*	This program packs and compares a string.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <string.h>

#define ALPHA \
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

//	Function Declarations
int  strCmpPk (char* S1, char* S2);
void strPk    (char* s1, char* s2);

int main (void)
{
//	Local Declarations
	int  cmpResult;
	char s1[80];
	char s2[80];

//	Statements
	printf("Please enter first string:\n");
	fgets (s1, 80, stdin);
	s1[strlen(s1) - 1] = '\0';
	
	printf("Please enter second string:\n");
	fgets (s2, 80, stdin);
	s2[strlen(s2) - 1] = '\0';

	cmpResult = strCmpPk (s1, s2);
	if (cmpResult < 0)
	    printf("string1 < string2\n");
	else if (cmpResult > 0)
	    printf("string1 > string2\n");
	else
	    printf("string1 == string2\n");

	return 0;
}	// main

/*	=================== strCmpPk ===================
	Packs two strings and then compares them.
	   Pre   s1 and s2 contain strings
	   Post  returns result of strcmp of packed strings
*/
int strCmpPk (char* s1, char* s2)
{
//	Local Declarations
	char s1In [80];
	char s1Out[81];
	char s2In [80];
	char s2Out[81];

//	Statements
	strncpy (s1In, s1, sizeof(s1In) - 1);
	strncpy (s2In, s2, sizeof(s2In) - 1);
	strPk (s1In, s1Out);
	strPk (s2In, s2Out);
	return (strcmp (s1Out, s2Out));
}	// strCmpPk

/*	=================== strPk ===================
	Deletes all non-alpha characters from s1 and 
	copies to s2.
	   Pre   s1 is a string 
	   Post  packed string in s2 
	         s1 destroyed
*/
void strPk (char* s1, char* s2)
{
//	Local Declarations
	int strSize;

//	Statements
	*s2 = '\0';
	while (*s1 != '\0')
	   {
	    // Find non-alpha character & replace 
	    strSize = strspn(s1, ALPHA);
	    s1[strSize] = '\0';
	    strncat (s2, s1, 79 - strlen(s2));
	    s1 += strSize + 1;
	   } // while
	return;
}	// strPk

/*	Results:
Please enter first string:
a b!c 234d
Please enter second string:
abcd
string1 == string2

Please enter first string:
abcd
Please enter second string:
aabb
string1 > string2
*/