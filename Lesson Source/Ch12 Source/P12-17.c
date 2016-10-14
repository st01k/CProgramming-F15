/*	================= terminate =================
	Release the memory occupied by buttons.
	   Pre   given elevator
	   Post  elevator memory is released
*/
void terminate (ELEVATOR* elev) 
{
// Statements
	free (elev->buttons); 
	return;
}	// terminate
//	================== End of Program ==================
