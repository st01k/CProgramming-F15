/*	Display the decimal value of selected characters,
	   Written by:
	   Date: 
*/
#include <stdio.h>

int main (void)
{
//	Local Declarations 
	char A         = 'A';
	char a         = 'a';
	char B         = 'B';
	char b         = 'b';
	char Zed       = 'Z';
	char zed       = 'z';
	char zero      = '0';
	char eight     = '8';
	char NL        = '\n';       // newline 
	char HT        = '\t';       // horizontal tab 
	char VT        = '\v';       // vertical tab 
	char SP        = ' ';        // blank or space 
	char BEL       = '\a';       // alert (bell)
	char dblQuote  = '"';        // double quote 
	char backSlash = '\\';       // backslash itself 
	char oneQuote  = '\'';       // single quote itself

//	Statements 
	printf("ASCII for char 'A'  is: %d\n",  A);
	printf("ASCII for char 'a'  is: %d\n",  a);
	printf("ASCII for char 'B'  is: %d\n",  B);
	printf("ASCII for char 'b'  is: %d\n",  b);
	printf("ASCII for char 'Z'  is: %d\n",  Zed);
	printf("ASCII for char 'z'  is: %d\n",  zed);
	printf("ASCII for char '0'  is: %d\n",  zero);
	printf("ASCII for char '8'  is: %d\n",  eight);
	printf("ASCII for char '\\n' is: %d\n", NL);
	printf("ASCII for char '\\t' is: %d\n", HT);
	printf("ASCII for char '\\v' is: %d\n", VT);
	printf("ASCII for char ' '  is: %d\n",  SP);
	printf("ASCII for char '\\a' is: %d\n", BEL);
	printf("ASCII for char '\"'  is: %d\n", dblQuote);
	printf("ASCII for char '\\'  is: %d\n", backSlash);
	printf("ASCII for char '\''  is: %d\n", oneQuote);

	return 0;
}	// main 

/*	Results:
ASCII for character 'A'  is: 65
ASCII for character 'a'  is: 97
ASCII for character 'B'  is: 66
ASCII for character 'b'  is: 98
ASCII for character 'Z'  is: 90
ASCII for character 'z'  is: 122
ASCII for character '0'  is: 48
ASCII for character '8'  is: 56
ASCII for character '\n' is: 10
ASCII for character '\t' is: 9
ASCII for character '\v' is: 11
ASCII for character ' '  is: 32
ASCII for character '\a' is: 7
ASCII for character '"'  is: 34
ASCII for character '\'  is: 92
ASCII for character '''  is: 39
*/