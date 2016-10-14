/*	================= runElevator =================== 
	Simulate the operation of the elevator. 
	   Pre   elevator structure has been initialized
	   Post  simulation is complete
*/
void runElevator (ELEVATOR* elev) 
{
//	Local Declarations
	char  buffer [81]; 
	int   floor; 
	char* pStrIn;
	
//	Statements
	printf("\n\nThis elevator goes from basement (0) "); 
	printf("to floor %d", TOP_FLOOR); 
	printf(    "\n\nType floors & press return key to start"); 
	printf(   "\nIf no new floors, just press return key."); 
	printf("\nTo quit, key EOF"); 
	printf("\n\nPlease enter floors: ");

	while (fgets(buffer, 81, stdin)) 
	   {
	    pStrIn = buffer;
	    while (*pStrIn != '\n')
	       {
	        // Locate next floor digit & convert to int 
	        while (*pStrIn == ' ')
	           pStrIn++;
	        if (!isdigit (*pStrIn)) 
	           {
	            printf("\aInvalid floor %c\n", *pStrIn); 
	            pStrIn++;
	           } // if
	        else
	           {
	            sscanf (pStrIn, "%d", &floor); 
	            if (floor  == elev->currentFloor) 
	                printf("\n\aAlready on floor %d.", 
	                       elev->currentFloor); 
	            else 
	               if (floor < 0 || floor > TOP_FLOOR) 
	                   printf("\n\a%d not a valid floor",
	                          floor); 
	               else
	                  elev->buttons [floor] = IN; 

	            // Synchronize sscanf & *pStrIn
	            while (isdigit (*pStrIn)) 
	               pStrIn++; 
	           } // else
	       } // while

	    move (elev);
	    printf("\n\nPlease enter floors: "); 
	} // while
	return;
}	// runElevator
