/*	================== timePass ==================
	This function simulates the concept of passing time by 
	executing an empty for-loop.
	   Pre   time to be passed (number of moments)
	   Post  time has passed
*/
void timePass  (int time) 
 {
//	Statements
	for (long i = 0; i < (time*  DELAY_FACTOR); i++) 
	   ;
	return; 
}	// timePass
