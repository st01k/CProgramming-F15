/*	=================== moveUp ===================
	This function simulates the movement of the elevator when
	it is going up.
	   Pre   given moving up elevator
	   Post  up simulation is displayed on the screen 
*/
void  moveUp (ELEVATOR* elev) 
{
//	Statements
	printf ("\nThe door is being closed …");
	printf ("\nWe are going up.");
	(elev->currentFloor)++;
	while (elev->buttons[elev->currentFloor] != IN)
	   {
	    printf("\n"); 
	    timePass (2); 
	    printf("\nPassing floor %d", elev->currentFloor);
	    printf("\n "); 
	    timePass (2);
	    (elev->currentFloor)++; 
	   } // while

	elev->buttons [elev->currentFloor] = OUT;
	printf("\nThe door is  being opened ...");
	printf("\n");
	printf("\n ***** FLOOR %d ***** ", elev->currentFloor); 
	printf("\n"); 
	timePass(4); 
	return;
}	// moveUp

/*	==================== moveDown ====================
	This function simulates the movement of the elevator when 
	it is going down.
	   Pre   given moving down elevator 
	   Post  down simulation is displayed on the screen 
*/
void moveDown (ELEVATOR* elev)
{
//	Statements
	printf("\nThe door is being closed ..."); 
	printf("\nWe are going down"); 
	(elev->currentFloor)--;
	while (elev->buttons [elev ->currentFloor] != IN) 
	   {
	    printf("\n"); 
	    timePass (2); 
	    printf("\nPassing floor %d", elev->currentFloor);
	    printf("\n"); 
	    timePass (2);
	    (elev->currentFloor)--; 
	   } // while
	elev->buttons [elev->currentFloor] = OUT;
	printf("\nThe door is being opened ...");
	printf("\n ");
	printf("\n ***** FLOOR %d ***** ", elev->currentFloor);
	printf("\n"); 
	timePass (4); 

	return;
}	// moveDown
