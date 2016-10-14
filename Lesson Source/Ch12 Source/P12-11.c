/*	================== initialize ================== 
	This function dynamically allocates memory locations for 
	the buttons and initializes the current floor to 1 to show 
	that the elevator is parked in the first floor. 
	   Pre   nothing 
	   Post  elevator created, all buttons reset, and
	         parked at first floor (not basement)
*/
void initialize (ELEVATOR* elev) 
{
//	Statements
	elev->buttons = calloc(TOP_FLOOR + 1,
	                       sizeof (BUTTON_STATUS));

	for (int i = 0; i <= TOP_FLOOR; i++) 
	   elev->buttons [i] = OUT;
	elev->currentFloor = 1; 

	return;
}	// initialize
