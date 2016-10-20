/*
******************************************************************
*                      Funkee'vert v.2.0                         *
*               Function-based Degree Converter                  *
*                  Chapter 4, Assignment 4.1                     *
*                    Author: Casey Murphy                        *
*                   Date Created: 9 Sep 15                       *
*                  Last Modified: 15 Sep 15                      *
*          Converts and degrees to and from celsius              *
*             and fahrenheit utilizing functions.                *
* -------------------------------------------------------------- *
*                        Change Log:                             *
*                                                                *
* 1.0 - Original                                                 *
* 1.1 - Added metafunctions: celsius, fahrenheit                 *
*       Added format functions: greeting, closing, separator     *
* 2.0 - Changed all variable pass by value to pass by reference  *
*       Added missing return statements on several functions     *
******************************************************************
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void  greeting       (void);                        // Greeting
void  separator      (void);                        // Separator - for formatting
void  closing        (void);                        // Closing
void  celsius        (void);                        // Meta function - Celsius
void  fahrenheit     (void);                        // Meta function - Fahrenheit
void  inputC         (float* tempC);                // User Input - Celsius
void  inputF         (float* tempF);                // User Input - Fahrenheit
void  convertCF      (float* tempC,                 // Conversion - C to F
                      float* convertedC);
void  convertFC      (float* tempF,                 // Conversion - F to C
                      float* convertedF);
void   printCel      (float* tempC,                 // Print Result - C to F
                      float* convertedC);
void   printFah      (float* tempF,                 // Print Result - F to C
                      float* convertedF);

int main()
{
    // Local Declarations

    // Statements
    greeting();
    celsius();
    separator();
    fahrenheit();
    separator();
    closing();
    separator();

    return 0;
} // End Main

/* ==================== greeting ====================
                prints welcome message
       Pre:     void
       Post:    void
*/
void greeting (void)
{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("|                                                                           |\n");
    printf("|                         Welcome to Funkee'vert!                           |\n");
    printf("|                                                                           |\n");
    printf("|      This program will convert Celsius to Fahrenheit and vice versa.      |\n");
    printf("|                                                                           |\n");
    printf("|                                  v.1.1                                    |\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\n\n");
    return;
}

/* ==================== separator ====================
            separator for organized formatting
       Pre:     void
       Post:    void
*/
void separator (void)
{
    printf("\n\n-----------------------------------------------------------------------------\n\n\n");
    return;
}

/* ==================== closing ====================
            displayed at the end of program
       Pre:     void
       Post:    void
*/
void closing (void)
{
    printf("  _    _  ___  ___  ___ ___  ___   ___                     _ _   ___  ___    \n");
    printf("   \\  /  |___ |___/  |   |  |___| |___   |    |   | \\__/  | | | |___ |___| \n");
    printf("    \\/   |___ |  \\_ _|_  |  |   | ____|  |___ |___| /  \\  | | | |___ |   |\n\n");
    return;
}

/* ==================== celsius ====================
              runs all celsius functions
       Pre:     void
       Post:    void
*/
void celsius (void)
{
    float tempC;
    float convertedC;

    inputC (&tempC);
    convertCF (&tempC, &convertedC);
    printCel (&tempC, &convertedC);
    return;
}

/* ==================== fahrenheit ====================
              runs all fahrenheit funcitons
       Pre:     void
       Post:    void
*/
void fahrenheit (void)
{
    float tempF;
    float convertedF;

    inputF (&tempF);
    convertFC (&tempF, &convertedF);
    printFah (&tempF, &convertedF);
    return;
}

/* ==================== inputC ====================
        gets celsius temperature from user input
       Pre:     tempC addr passed
       Post:    value assigned to tempC addr
*/
void inputC (float* tempC)
{
    printf ("Enter a temperature in Celsius:    \t\t\t\t");
    scanf ("%f", tempC);
    return;
}

/* ====================  inputF ====================
       gets fahrenheit temperature from user input
       Pre:         tempF addr passed
       Post:        value assigned to tempF addr
*/
void inputF (float* tempF)
{
    printf ("Enter a temperature in Fahrenheit: \t\t\t\t");
    scanf ("%f", tempF);
    return;
}

/*  =================== convertCF ===================
           converts user input into fahrenheit
       Pre:     tempC and convertedC addrs' passed
       Post:    value assigned to convertedC addr
*/
void convertCF (float* tempC, float* convertedC)
{
   *convertedC = (*tempC * (9.0/5.0) + 32);
   return;
}

/* ====================  convertFC ====================
            converts user input into celsius
       Pre:     tempF and convertedF addrs' passed
       Post:    value assigned to convertedF addr
*/
void convertFC (float* tempF, float* convertedF)
{
    *convertedF = ((*tempF - 32) * (5.0/9.0));
    return;
}

/* ====================  printCel ====================
         prints user input and converted temp
       Pre:     user input and converted value addrs'
       Post:    void
*/
void  printCel (float* tempC, float* convertedC)
{
    printf ("\n\n\t\t\t%.2f degrees C = %.2f degrees F", *tempC, *convertedC);
    return;
}

/* ====================  printFah ====================
        prints user input and converted temp
       Pre:     user input and converted value addrs'
       Post:    void
*/
void  printFah (float* tempF, float* convertedF)
{
    printf ("\n\n\t\t\t%.2f degrees F = %.2f degrees C", *tempF, *convertedF);
    return;
}
