/*	Convert English to Morse or Morse to English.
	   Written by: 
	   Date Written: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define FLUSH while(getchar() != '\n') 
#define STR_LEN 81

//	Function Declarations
char menu         (void); 
void getInput     (char* inStr);
void printOutput  (char* inStr, char* outSt); 
bool encode       (char* (*encDec)[2], 
                   char* inStr, 
                   char* outStr); 
bool decode       (char* (*encDec)[2], 
                   char* inStr,
                   char* outStr); 
int  convert      (char* (*encDec)[2], 
                   char* s1, 
                   int   col, 
                   char* s2); 

//	Morse Code Includes--Not in Text
#include "P11-19.c"
#include "P11-20.c"
#include "P11-21.c"
#include "P11-22.c"
#include "P11-23.c"
#include "P11-24.c"

int main (void) 
{
//	Local Declarations
	char* encDec [27][2] = 
	   {
	    { "A", ".-#" }, 
	    { "B", "-...#" }, 
	    { "C", "-.-.#" }, 
	    { "D", "-..#" }, 
	    { "E", ".#" }, 
	    { "F", "..-.#" }, 
	    { "G", "--.#" }, 
	    { "H", "....#" }, 
	    { "I", "..#" }, 
	    { "J", ".---#" }, 
	    { "K", "-.-#" }, 
	    { "L", ".-..#" }, 
	    { "M", "--#" }, 
	    { "N", "-.#" }, 
	    { "O", "---#" }, 
	    { "P", ".--.#" }, 
	    { "Q", "--.-#" }, 
	    { "R", ".-.#" }, 
	    { "S", "...#" }, 
	    { "T", "-#" }, 
	    { "U", "..-#" }, 
	    { "V", "...-#" }, 
	    { "W", ".--#" }, 
	    { "X", "-..-#" }, 
	    { "Y", "-.--#" }, 
	    { "Z", "--..#" }, 
	    { " ", "$$#" }, 
	   }; // Encode / Decode array
	char inStr  [STR_LEN]; 
	char outStr [STR_LEN]; 
	char option; 
	bool done = false; 

//	Statements
	while (!done)
	   {
	    option = menu ();
	    switch (option) 
	       {
	        case 'E' :  
	               getInput (inStr);
	               if (!encode (encDec, inStr, outStr))
	                  {
	                   printf("Error! Try again"); 
	                   break; 
	                  } // if
	               printOutput (inStr, outStr); 
	               break;
	        case 'D' : getInput (inStr); 
	               if (!decode (encDec, inStr, outStr))
	                  {
	                   printf("Error! Try again"); 
	                   break;
	                  } // if
	               printOutput (inStr, outStr);
	               break;
	        default :  
	               done = true;
	               printf("\nEnd of Morse Code.\n");
	               break;
	       } // switch
	   } // while
	return 0;
}	// main

/*	Results
*/