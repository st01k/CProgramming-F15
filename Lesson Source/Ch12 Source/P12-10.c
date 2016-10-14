/*	This program simulates the operation of an elevator.
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define TOP_FLOOR 10
#define DELAY_FACTOR 10000

//	Global Type Declarations
typedef enum {OUT, IN} BUTTON_STATUS;
typedef enum {DOWN, STOP, UP} DIRECTION_STATUS;
typedef struct 
	{
	 int            currentFloor;
	 BUTTON_STATUS* buttons;
	} ELEVATOR; 

//	Function Declarations
void initialize      (ELEVATOR* elev); 
void runElevator     (ELEVATOR* elev); 
void terminate       (ELEVATOR* elev); 
void move            (ELEVATOR* elev); 
bool anyUpRequest    (ELEVATOR* elev); 
bool anyDownRequest  (ELEVATOR* elev); 
void moveUp          (ELEVATOR* elev); 
void moveDown        (ELEVATOR* elev); 
void timePass        (int m); 

//	Subfunction Library Includes -- Not in text
#include "P12-11.c"
#include "P12-12.c"
#include "P12-13.c"
#include "P12-14.c"
#include "P12-15.c"
#include "P12-16.c"
#include "P12-17.c"
int main (void) 
{
//	Local Declarations
ELEVATOR elevator; 

//	Statements
	initialize  (&elevator);
	runElevator (&elevator);
	terminate   (&elevator);
	return 0;
}	// main
