/*      Reformat IP string address to long integer.
           Written by:
           Date:
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//      Global Structures
        typedef union
           {
            unsigned char chAddr[4];
            unsigned long numAddr;
           } IP_ADDR;

int main (void)
{
//      Local Declarations
        IP_ADDR addr;
        char*   parser;
        char    strAddr[16] = "153.18.8.105";

//      Statements
        // Convert first address segment
        parser = strtok (strAddr, ".");
	    addr.chAddr[3] = strtol (parser, (char**)NULL, 10);

 	    for (int i = 2; i >= 0; i--)
            {
             // Convert decimal dot positions 2, 1, 0
             parser = strtok (NULL, ".");
             addr.chAddr[i] =
                  strtol (parser, (char**)NULL, 10);
            } // for

        // Now print results
        printf ("IP decimal dot   : %d.%d.%d.%d\n",
 	              addr.chAddr[3], addr.chAddr[2],
                  addr.chAddr[1], addr.chAddr[0]);
        printf ("IP binary        : %lu\n", addr.numAddr);
        return 0;
}       // main

/*	Results: 
IP decimal dot   : 153.18.8.105
IP binary        : 2568095849
*/