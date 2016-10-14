/*	==================== convert ====================
	Looks up code and converts to opposite format
	   Pre   encDec is a pointer decoding table
	         s1 is string being converted
	         s2 is output string
	          col is code: 0 for character to Morse
	                       1 for Morse to character
	   Post  converted output s2
*/
int convert (char* (*encDec)[2],
             char* s1, int col, char* s2)
{
//	Local Declarations
	bool found = false;
	int  i;

//	Statements
	for (i = 0; i < 27 && !found; i++) 
	   found = !strcmp(s1, encDec[i][col]); 

	if (found)
	   strcpy (s2, encDec [i - 1][(col + 1) % 2]); 
	else
	   *s2 = '\0';

	return found;
}	// convert
//	================= End of Program ================ 
