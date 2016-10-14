/*	This program uses a structure to simulate the time.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

typedef struct 
	{
	 int hr;
	 int min;
	 int sec;
	} CLOCK;

//	Function Declaration 
void increment (CLOCK* clock);
void show      (CLOCK* clock);

int main (void)
{
//	Local Declaration 
	CLOCK clock = {14, 38, 56}; 

//	Statements 
	for(int i = 0; i < 6; ++i) 
	   {
	    increment (&clock);
	    show (&clock);
	   } // for
	return 0;
}	// main 

/*	==================== increment ====================
	This function accepts a pointer to clock and  
	increments the time by one second.
	   Pre   previous clock setting
	   Post  clock incremented by one second.
*/
void increment (CLOCK* clock) 
{
//	Statements 
	(clock->sec)++; 
	if (clock->sec == 60)
	   {
	    clock->sec = 0;
	    (clock->min)++;
	    if (clock->min == 60)
	       {
	        clock->min = 0; 
	        (clock->hr)++; 
	        if (clock->hr == 24) 
	            clock->hr = 0; 
	       } // if 60 min
	   } // if 60 sec
	return; 
}	// increment

/* ====================== show ======================
	This function shows the current time in military form.
	   Pre   clock time 
	   Post  clock time displayed
*/
void show (CLOCK* clock) 
{
//	Statements 
	printf("%02d:%02d:%02d\n",
	        clock->hr, clock->min, clock->sec); 
	return;
}	// show

/*	Results:
14:38:57
14:38:58
14:38:59
14:39:00
14:39:01
14:39:02
*/