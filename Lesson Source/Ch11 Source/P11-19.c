/*	==================== menu ====================
	Display menu of choices; return selected character.
	   Pre   nothing 
	   Post  returns validated option code 
*/
char menu (void) 
{
//	Local Declarations
	char  option;
	bool  validData;

//	Statements
	printf("\t\t\tM E N U \n"); 
	printf("\t\tE)  encode \n"); 
	printf("\t\tD)  decode \n"); 
	printf("\t\tQ)  quit \n"); 

	do
	   {
	    printf ("\nEnter option: press return key: "); 
	    option = toupper (getchar());
	    FLUSH;
	    if (option == 'E' || option == 'D' || 
	        option == 'Q')
	       validData = true;
	    else
	       {
	        validData = false;
	        printf("\aEnter only one option\n"); 
	        printf(" \tE, D, or Q\n "); 
	       } // else
	   } while (!validData); 
	return option; 
}	// menu
