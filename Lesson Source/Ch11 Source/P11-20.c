/*	==================== getInput ====================
	Reads input string to be encoded or decoded.
	   Pre   inStr is a pointer to the input area 
	   Post  string read into input area
*/
void getInput (char* inStr) 
{
//	Statements
	printf ("\nEnter line of text to be coded: \n");
	fgets  (inStr, STR_LEN, stdin);
	
	// Eliminate newline in input string
	*(inStr-1 + strlen(inStr)) = '\0'; 
	
	if (isalpha(*inStr) && strlen(inStr) > 16)
	   {
	    // Exceeds English input length 
	    printf("\n***WARNING: Input length exceeded: ");
	    printf("Only 16 chars will be encoded.\a\a\n");
	    *(inStr + 16) = '\0';
	   } // if
	return;
}	// getInput
