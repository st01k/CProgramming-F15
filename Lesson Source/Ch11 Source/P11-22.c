/* ==================== encode ====================
	Transforms character data to Morse Code 
	   Pre     encDec is the conversion table
	           inStr contains data to be put into Morse
	   Post    data have been encoded in outStr
	   Return  true  if all valid characters; 
	           false if invalid character found
*/
bool encode (char* (*encDec)[2], 
             char* inStr, char* outStr)
{
//	Local Declarations
	char s1[2];
	char s2[6];
	int  error = 0;

//	Statements
	outStr[0] = '\0';
	while (*inStr != '\0' && !error) 
	   {
	    s1[0] = toupper(*inStr);
	    s1[1] = '\0';
	    error = !convert (encDec, s1, 0, s2); 
	    strcat (outStr, s2); 
	    inStr++;
	   } // while
	return (!error); 
}	// encode
