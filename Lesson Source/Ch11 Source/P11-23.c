/* ==================== decode ====================
	Transforms Morse Code data to character string
	   Pre    encDec is the conversion table
	          inStr contains data to transform to string
	   Post   data encoded and placed in outStr
	   Return true  if all valid characters; 
	          false if invalid character found
*/
bool decode (char* (*encDec)[2], 
             char* inStr, char* outStr)
{
//	Local Declarations
	char  s1[6];
	char  s2[2];
	bool  error = false;
	int   i;

//	Statements
	outStr[0] ='\0';
	while (*inStr != '\0' && !error) 
	   {
	    for (i = 0; i < 5 && *inStr != '#'; i++, inStr++) 
	        s1[i] = *inStr;

	    s1[i]   = *inStr;
	    s1[++i] = '\0';

	    error = !convert (encDec, s1, 1, s2);
	    strcat (outStr, s2);
	    inStr++;
	   } // while
	return (!error);
} // decode
