/*	=================== move ===================
	Moves the elevator to a requested floor. It stops
	the elevator after responding to one request.
	   Pre   given elevator
	   Post  elevator has been moved--while it is 
	         moving, the floors are called out
*/
void move (ELEVATOR* elev) 
{
//	Local Declarations
	static DIRECTION_STATUS direction = STOP;
	
	bool anyUp;
	bool anyDown;

//	Statements
	anyUp    = anyUpRequest   (elev);
	anyDown  = anyDownRequest (elev);

	if (direction == UP)
	   {
	    if (!anyUp && anyDown)
	        direction = DOWN;
	    else
	        if (!anyUp && !anyDown)
	            direction = STOP;
	   } // UP
	
	else if (direction == DOWN)
	   {
	    if (!anyDown && anyUp)
	        direction = UP;
	    else
	        if (!anyDown && !anyUp)
	            direction = STOP;
	   } // DOWN
	
	else if (direction == STOP)
	   {
	    if (anyUp)
	        direction = UP;
	    else
	        if (anyDown)
	            direction = DOWN;
	   } // else if stop

	if (direction == UP) 
	    moveUp (elev); 
	else
	    if (direction == DOWN)
	        moveDown (elev);
	    else
	        printf("\n***** NO BUTTON PRESSED ***** "); 
	return;
}	// move
