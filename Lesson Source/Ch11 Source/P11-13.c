/*	Demonstrate string to long function.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//	Local Declarations
	long  num;
	char* ptr;

//	Statements
	num = strtol ("12345 Decimal constant: ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	num = strtol ("11001 Binary constant : ", &ptr, 2);
	printf("%s %ld\n", ptr, num);

	num = strtol ("13572 Octal constant  : ", &ptr, 8);
	printf("%s %ld\n", ptr, num);

	num = strtol (" 7AbC Hex constant    : ", &ptr, 16);
	printf("%s %ld\n", ptr, num);

	num = strtol ("11001 Base 0-Decimal  : ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	num = strtol ("01101 Base 0-Octal    : ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	num = strtol ("0x7AbC Base 0-Hex      : ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	num = strtol ("Invalid input    : ", &ptr, 0);
	printf("%s %ld\n", ptr, num);

	return 0;
}	// main

/*	Results:
   Decimal constant:  12345
   Binary constant :  25
   Octal constant  :  6010
   Hex constant    :  31420
   Base 0-Decimal  :  11001
   Base 0-Octal    :  577
   Base 0-Hex      :  31420
   Invalid input   :  0
*/