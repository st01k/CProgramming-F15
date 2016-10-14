/*	Test driver (compile only) for process-control system
	    Written by:
	    Date:
*/
#include <stdio.h>
#include <stdbool.h>

//	Function Declarations
int  getTemperature  (void);
void turnOnHeater    (void);
void turnOffHeater   (void);
void turnOnAirCond   (void);
void turnOffAirCond  (void);

// ...

int main (void)
{
//	Local Declarations 
	int temp;
	
//	Statements 
	// ...

while (true)
	{
	 temp = getTemperature();
	 if (temp < 68)
	     turnOnHeater();
	 else if (temp > 78)
	     turnOnAirCond();
	 else
	    {
	     turnOffHeater();
	     turnOffAirCond();
	    } // else 
	} // while true   

	// ...

}	// main 

