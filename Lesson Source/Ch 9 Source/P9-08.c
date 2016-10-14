/*	Test driver for function that converts integer into
	time--hours, minutes, seconds.
	   Written by:
	   Date:
*/
#include <stdio.h>

//	Prototype Declarations 
	int secToHours (long time, int *hours, int *minutes, int *seconds);
	
int main (void)
{
//	Local Definitions 
	int  hours;
	int  minutes;
	int  seconds;
	long time;
	
//	Statements 
	printf("Enter time in seconds: "); 
	scanf ("%ld", &time);
	
	if (secToHours (time, &hours, &minutes, &seconds))
	    printf("%ld seconds is %d:%d:%d\n", 
	            time, hours, minutes, seconds);
	else
	    printf("Your time was invalid\n\a");
	    
	printf("Thank you\n");
	return 0;
}	// main 

/*	=================== secToHours ===================
	Given time in seconds, convert it to hours, minutes,
	and seconds.
	   Pre    time in seconds
	          addresses of hours, minutes, seconds
	   Post   hours, minutes, seconds calculated
	   Return error indicator--1 success, 0 bad time
*/
int secToHours (long time, 
                int* hours, int* minutes, int* seconds)
{
//	Local Declarations 
	long localTime;

//	Statements 
	localTime = time;
	*seconds  = localTime % 60;
	localTime = localTime / 60;
	
	*minutes  = localTime % 60;
	
	*hours    = localTime / 60;
	
	if (*hours > 24)
	   return 0;
	else
	   return 1;
}	// secToHours

/*	Results:
	Enter time in seconds: 0
	0 seconds is 0:0:0
	Thank you

Second Run	
	86400 seconds is 24:0:0

Third Run	
	43261 seconds is 12:1:1

Fourth Run
	119 seconds is 0:1:59

Fifth Run
	Enter time in seconds: 96400
	Your time was invalid
	Thank you
*/
