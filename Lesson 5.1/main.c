/*
******************************************************************
*               Parking Lot Calculator ver 1.0                   *
*                                                                *
*                  Chapter 5, Assignment 5.1                     *
*                    Author: Casey Murphy                        *
*                   Date Created: 19 Sep 15                      *
*                  Last Modified: 24 Sep 15                      *
*          Calculates the fee for using a parking lot            *
*       based on vehicle type and time spent in the lot.         *
******************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>         //used for towed status
#include <ctype.h>           //used for islower
#include <math.h>            //for future improvements

//constants
#define OPEN      05          //open time           - hour of day, 24 hr format
#define CLOSE     00          //close time          - hour of day, 24 hr format
#define C_RATE_1  0.00        //car first rate      - $0.00/hr first 3 hrs
#define C_RATE_2  1.50        //car sec rate        - $1.50/hr after 3 hrs
#define T_RATE_1  1.00        //truck first rate    - $1.00/hr first 2 hrs
#define T_RATE_2  2.30        //truck sec rate      - $2.30/hr after 2 hrs
#define B_RATE_1  2.00        //bus first rate      - $2.00/hr first 1 hr
#define B_RATE_2  3.70        //bus sec rate        - $3.70/hr after 1 hr
#define C_HOURS   3           //car initial hours   - hours that initial rate applies
#define T_HOURS   2           //truck initial hours - hours that initial rate applies
#define B_HOURS   1           //bus initial hours   - hours that initial rate applies

//function declarations
void    getData     (char*  vehicleType,        //meta-function
                     int*   hourIn,
                     int*   minIn,
                     int*   hourOut,
                     int*   minOut);
void    getVType    (char*  vehicleType);       //gets vehicle type input
void    getTimeIn   (int*   hourIn,             //gets time in input
                     int*   minIn);
void    getTimeOut  (int*   hourOut,            //gets time out input
                     int*   minOut);
//-----------------------------------------------------------------------
void    calculate   (char   vehicleType,        //meta-function
                     int    hourIn,
                     int    minIn,
                     int    hourOut,
                     int    minOut,
                     int*   totHours,
                     int*   totMin,
                     int*   rndHours,
                     float* charge,
                     bool*  towFlag);
void    towed       (int    hourIn,             //checks hours for towing
                     int    hourOut,
                     bool*  towFlag);
void    totTime     (int    hourIn,             //calculates total time
                     int    minIn,
                     int    hourOut,
                     int    minOut,
                     int*   totHours,
                     int*   totMin);
void    totFee      (char   vehicleType,        //calculates total rounded fee
                     int*    totHours,
                     int*    totMin,
                     int*   rndHours,
                     float* charge);
//-----------------------------------------------------------------------
void    report      (char   vehicleType,        //meta-function
                     int    hourIn,
                     int    minIn,
                     int    hourOut,
                     int    minOut,
                     int    totHours,
                     int    totMin,
                     int    rndHours,
                     float  charge,
                     bool   towFlag);
void    printHead   (void);                     //prints report header
void    printVType  (char   vehicleType);       //prints vehicle type
void    printTime   (int    hourIn,             //prints time info
                     int    minIn,
                     int    hourOut,
                     int    minOut,
                     int    totHours,
                     int    totMin,
                     int    rndHours);
void    printFee    (float  charge);            //prints fee
void    printTow    (bool   towFlag);           //prints tow status if triggered
//-----------------------------------------------------------------------
void    greeting    (void);                     //prints initial greeting
//-----------------------------------------------------------------------

int main(void)
{
    char    q           = 'y';          //while loop control

    do
    {
        //local declarations
        char    vehicleType = ' ';          //type of vehicle     - user input
        int     hourIn      = 0;            //hour arrived        - user input
        int     minIn       = 0;            //minute arrived      - user input
        int     hourOut     = 0;            //hour departed       - user input
        int     minOut      = 0;            //minute departed     - user input
        int     totHours    = 0;            //total hours         - calculated
        int     totMin      = 0;            //total minutes       - calculated
        int     rndHours    = 0;            //total rounded hours - calculated
        float   charge      = 0.0;          //total fee           - calculated
        bool    towFlag     = 0;            //tow status          - calculated


        //statements
        greeting    ();
        getData     (&vehicleType, &hourIn, &minIn, &hourOut, &minOut);
        calculate   (vehicleType, hourIn, minIn, hourOut, minOut,
                    &totHours, &totMin, &rndHours, &charge, &towFlag);
        report      (vehicleType, hourIn, minIn, hourOut, minOut, totHours,
                    totMin, rndHours, charge, towFlag);
        printf      ("\n\nWould you like to run this program again (Y/N)? ");
        scanf       (" %c", &q);
        printf      ("\n\n");
    }   while (q == 'y');

    return 0;
}

//----------------------------------------------------------------------
// meta-function to get user input
//-----------------------------------------------------------------------
void    getData (char* vehicleType,
                 int*  hourIn,
                 int*  minIn,
                 int*  hourOut,
                 int*  minOut)
{
    getVType    (vehicleType);
    getTimeIn   (hourIn, minIn);
    getTimeOut  (hourOut, minOut);

    return;
}

// subfunction to get vehicle type
//-----------------------------------------------------------------------
void    getVType    (char* vehicleType)
{
    printf ("What type of vehicle did you park today?\n\n");
    printf ("Enter C for HoverCar, B for HoverBus, or T for HoverTruck");
    printf ("\n\n");
    printf ("Your selection: ");
    scanf  ("%c", vehicleType);
    printf ("\n-----------------------------------------------------------");
    printf ("\n");
    *vehicleType = tolower(*vehicleType);
    switch (*vehicleType)
    {
        case 'c' :  break;
        case 'b' :  break;
        case 't' :  break;
        default  :  printf  ("\nInvalid Response\n");
                    exit    (1);
    }

    return;
}


// subfunction to get time in
//-----------------------------------------------------------------------
void    getTimeIn   (int* hourIn,
                     int* minIn)
{
    printf ("\nEnter the hour in which you arrived (0 - 23): ");
    scanf   ("%d", hourIn);
    if (*hourIn < 0 || *hourIn > 23)
    {
        printf("\nInvalid Response\n");
        exit    (2);
    }
    printf ("\nEnter the minute in which you arrived (0 - 59): ");
    scanf   ("%d", minIn);
    if (*minIn < 0 || *minIn > 59)
    {
        printf("\nInvalid Response\n");
        exit    (3);
    }

    return;
}

// subfunction to get time out
//----------------------------------------------------------------------
void    getTimeOut  (int* hourOut,
                     int* minOut)
{
    printf ("\nEnter the hour in which you departed (0 - 23): ");
    scanf   ("%d", hourOut);
    if (*hourOut < 0 || *hourOut > 23)
    {
        printf("\nInvalid Response\n");
        exit    (4);
    }
    printf ("\nEnter the minute in which you departed (0 - 59): ");
    scanf   ("%d", minOut);
    if (*minOut < 0 || *minOut > 59)
    {
        printf("\nInvalid Response\n");
        exit    (5);
    }

    return;
}

//-----------------------------------------------------------------------
// meta-funtion calculations and processing
//-----------------------------------------------------------------------
void    calculate   (char   vehicleType,
                     int    hourIn,
                     int    minIn,
                     int    hourOut,
                     int    minOut,
                     int*   totHours,
                     int*   totMin,
                     int*   rndHours,
                     float* charge,
                     bool*  towFlag)
{
    towed       (hourIn, hourOut, towFlag);
    totTime     (hourIn, minIn, hourOut, minOut,
                 totHours, totMin);
    totFee      (vehicleType, totHours, totMin, rndHours, charge);

    return;
}

// subfunction to determine tow away status
//-----------------------------------------------------------------------
void    towed       (int    hourIn,
                     int    hourOut,
                     bool*  towFlag)
{
    if (hourIn >= CLOSE && hourIn < OPEN)
    {
        *towFlag = 1;
    }
    else
    {
        *towFlag = 0;
    }
    if (hourOut >= CLOSE && hourOut < OPEN)
    {
        *towFlag = 1;
    }
    else
    {
        *towFlag = 0;
    }

    return;
}

// subfunction to calculate total time in parking lot
//-----------------------------------------------------------------------
void    totTime     (int    hourIn,
                     int    minIn,
                     int    hourOut,
                     int    minOut,
                     int*   totHours,
                     int*   totMin)
{
    int tempHr;
    int tempMin;

    if (minOut < minIn)
    {
        tempMin     = minOut  + 60;
        tempHr      = hourOut - 1;
        *totHours   = tempHr  - hourIn;
        *totMin     = tempMin - minIn;
    }
    else
    {
        *totHours   = hourOut - hourIn;
        *totMin     = minOut  - minIn;
    }

    return;
}

// subfunction to calculate total rounded fee
//-----------------------------------------------------------------------
void    totFee      (char   vehicleType,
                     int*    totHours,
                     int*    totMin,
                     int*   rndHours,
                     float* charge)
{
    float   rate1;
    float   rate2;
    float   tempCHolder;
    float   holder1;
    int     holder2;
    float   holder3;
    int     iHours;

    switch (vehicleType)
    {
        case 'c' :  rate1   = C_RATE_1;
                    rate2   = C_RATE_2;
                    iHours  = C_HOURS;
                    break;
        case 'b' :  rate1   = B_RATE_1;
                    rate2   = B_RATE_2;
                    iHours  = B_HOURS;
                    break;
        case 't' :  rate1   = T_RATE_1;
                    rate2   = T_RATE_2;
                    iHours  = T_HOURS;
                    break;
        default  :  exit (6);
    }
    if (*totMin > 0)
    {
        tempCHolder = ceil(*totMin / 100.00);
        *rndHours   = *totHours + tempCHolder;
    }
    else
    {
        *rndHours = *totHours;
    }
    if (*rndHours >= iHours)
    {
        holder1 = iHours * rate1;
        holder2 = *rndHours - iHours;
        holder3 = (float)holder2 * rate2;
        *charge = holder1 + holder3;
    }
    else
    {
     *charge = iHours * rate1;
    }

    return;
}

//-----------------------------------------------------------------------
//  meta-function to print final report
//-----------------------------------------------------------------------
void    report      (char   vehicleType,
                     int    hourIn,
                     int    minIn,
                     int    hourOut,
                     int    minOut,
                     int    totHours,
                     int    totMin,
                     int    rndHours,
                     float  charge,
                     bool   towFlag)
{
    printHead   ();
    printVType  (vehicleType);
    printTime   (hourIn, minIn, hourOut, minOut,
                 totHours, totMin, rndHours);
    printFee    (charge);
    printTow    (towFlag);

    return;
}

// subfunction to print receipt header
//-----------------------------------------------------------------------
void    printHead   (void)
{
    printf ("\n-----------------------------------------------------------");
    printf  ("\n\n");
    printf  ("\t\t  PARKING LOT CHARGE");
    printf  ("\n\n");

    return;
}

// subfunction to print vehicle type
//-----------------------------------------------------------------------
void    printVType  (char   vehicleType)
{
    printf ("\t\tVehicle Type: ");
    switch (vehicleType)
    {
        case 'c' : printf ("HoverCar\n\n");
                   break;
        case 'b' : printf ("HoverBus\n\n");
                   break;
        case 't' : printf ("HoverTruck\n\n");
                   break;
        default  : exit (7);
    }

    return;
}

// subfunction to print time info
//-----------------------------------------------------------------------
void    printTime   (int    hourIn,
                     int    minIn,
                     int    hourOut,
                     int    minOut,
                     int    totHours,
                     int    totMin,
                     int    rndHours)
{
    printf ("\t\tTIME  IN:      \t%.2d:%.2d\n", hourIn, minIn);
    printf ("\t\tTIME OUT:      \t%.2d:%.2d\n", hourOut, minOut);
    printf ("\t\t               \t-----\n");
    printf ("\t\tPARKING  TIME: \t%.2d:%.2d\n", totHours, totMin);
    printf ("\t\tROUNDED TOTAL: \t   %.2d\n", rndHours);
    printf ("\n");

    return;
}

// subfunction to print total rounded fee
//-----------------------------------------------------------------------
void    printFee    (float  charge)
{
    printf ("\t\tTOTAL  CHARGE:\t$%.2f\n", charge);
    printf ("\n-----------------------------------------------------------");

    return;
}

// subfunction to print tow away status
//-----------------------------------------------------------------------
void    printTow    (bool towFlag)
{
    if (towFlag)
    {
        printf ("\n\n\t    Your vehicle has been towed away.\n");
        printf ("\n-----------------------------------------------------------");
    }

    return;
}

//-----------------------------------------------------------------------
// meta-function to print inital greeting - no subfunctions
//-----------------------------------------------------------------------
void    greeting    (void)
{
    printf ("\n\n  T     E     S     L     -     A     -     L     O     T");
    printf ("\n-----------------------------------------------------------");
    printf ("\nWe transcend the limits of space and time in order to bring");
    printf ("\nyou the most excellent parking experience of your life!"    );
    printf ("\n\nBe sure to check out our chronovisors and teleporters!"   );
    printf ("\n-----------------------------------------------------------");
    printf ("\n\nThis utility will calculate the amount of money you would");
    printf ("\nhave owed for your stay if the world still operated on such");
    printf ("\nan archaic and self-defeating system as the paper note.\n"  );
    printf ("\n-----------------------------------------------------------");
    printf ("\n|\t     OPERATING HOURS: %.2d:00 to %.2d:00\t\t  |", OPEN, CLOSE);
    printf ("\n-----------------------------------------------------------");
    printf ("\n\n\n");

    return;
}
