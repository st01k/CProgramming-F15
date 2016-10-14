/*	================= anyUpRequest =================== 
	This function checks to see if any request is for a floor 
	above the current floor.
	   Pre   given elevator
	   Post  return 1 if button above current floor pushed
	         return 0 otherwise.
*/
bool anyUpRequest (ELEVATOR* elev) 
{
//	Local Declarations
	bool  isAny = false;

//	Statements
	for (int check = elev->currentFloor; 
	     check <= TOP_FLOOR && !isAny; 
	     check++) 
	   isAny = (elev->buttons[check] == IN);
	return isAny;
}	// anyUpRequest

/*	================== anyDownRequest ================== 
	This function checks to see if any request is for a 
	floor below the current floor.
	   Pre   given elevator 
	   Post  return 1 if button below current floor pushed
	         return 0 otherwise
*/
bool anyDownRequest (ELEVATOR* elev)
{
//	Local Declarations
	bool isAny = false;

//	Statements
	for (int check = elev->currentFloor;
	         check >=  0;
	         check--)
	   isAny = isAny || (elev->buttons[check] == IN);
	return isAny;
}	// anyDownRequest
