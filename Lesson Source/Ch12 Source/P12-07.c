/*	Demonstrate union of short integer and two characters.
	   Written by:
	   Date: 
*/
#include <stdio.h>

//	Global Declarations
	typedef union 
	   {
	    short  num;
	    char   chAry[2];
	   } SH_CH2;

int main (void)
{
//	Local Declarations
	SH_CH2 data;
	
//	Statements
	data.num = 16706;
	
	printf("Short: %hd\n", data.num);
	printf("Ch[0]: %c\n",  data.chAry[0]);
	printf("Ch[1]: %c\n",  data.chAry[1]);
	
	return 0;
}	// main

/*	Results:
Short: 16706
Ch[0]: A
Ch[1]: B
*/