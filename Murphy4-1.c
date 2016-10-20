/*
************************************************************
*                      Funkee'vert v.1.1                   *
*            Function-based Degree Converter               *
*               Chapter 4, Assignment 4.1                  *
*                 Author: Casey Murphy                     *
*                Date Created: 9 Sep 15                    *
*               Last Modified: 13 Sep 15                   *
*       Converts and degrees to and from celsius           *
*          and fahrenheit utilizing functions.             *
************************************************************
*/

/* Preprocessor Directives */
#include <stdio.h>

/* Function Declarations */
void  greeting      (void);                         /* Greeting */
void  separator     (void);                         /* Separator - for formatting */
void  closing       (void);                         /* Closing */
void  celsius       (void);                         /* Meta function - Celsius */
void  fahrenheit    (void);                         /* Meta function - Fahrenheit */
float inputC        (void);                         /* User Input - Celsius */
float inputF        (void);                         /* User Input - Fahrenheit */
float convertCF     (float tempC);                  /* Conversion - C to F */
float convertFC     (float tempF);                  /* Conversion - F to C */
void  printCel      (float tempC,                   /* Print Result - C to F */
                     float convertedC);
void  printFah      (float tempF,                   /* Print Result - F to C */
                     float convertedF);

int main()
{
    /* Local Declarations */

    /* Statements */
    greeting();
    celsius();
    separator();
    fahrenheit();
    separator();
    closing();
    separator();

    return 0;
} /* End Main */

/* ==================== greeting ====================
                prints welcome message
       Pre:     void
       Post:    void
*/
void greeting(void)
{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("|                                                                           |\n");
    printf("|                         Welcome to Funkee'vert!                           |\n");
    printf("|                                                                           |\n");
    printf("|      This program will convert Celsius to Fahrenheit and vice versa.      |\n");
    printf("|                                                                           |\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\n\n");
    return;
}

/* ==================== separator ====================
            separator for organized formatting
       Pre:     void
       Post:    void
*/
void separator(void)
{
    printf("\n\n-----------------------------------------------------------------------------\n\n\n");
}

/* ==================== closing ====================
            displayed at the end of program
       Pre:     void
       Post:    void
*/
void closing(void)
{
    printf("  _    _  ___  ___  ___ ___  ___   ___                     _ _   ___  ___    \n");
    printf("   \\  /  |___ |___/  |   |  |___| |___   |    |   | \\__/  | | | |___ |___| \n");
    printf("    \\/   |___ |  \\_ _|_  |  |   | ____|  |___ |___| /  \\  | | | |___ |   |\n\n");
}

/* ==================== celsius ====================
              runs all celsius functions
       Pre:     void
       Post:    void
*/
void celsius ()
{
    float tempC;
    float convertedC;

    tempC = inputC();
    convertedC = convertCF(tempC);
    printCel(tempC, convertedC);
}

/* ==================== fahrenheit ====================
              runs all fahrenheit funcitons
       Pre:     void
       Post:    void
*/
void fahrenheit ()
{
    float tempF;
    float convertedF;

    tempF = inputF();
    convertedF = convertFC(tempF);
    printFah(tempF, convertedF);
}

/* ==================== inputC ====================
       Return:      user input of temp C - float
       Pre:         void
       Post:        value for c returned to tempC
*/
float inputC (void)
{
    float c;

    printf("Enter a temperature in Celsius:    \t\t\t\t");
    scanf("%f", &c);
    return c;
}

/* ====================  inputF ====================
       Return:      user input of temp F - float
       Pre:         void
       Post:        value of f returned to tempF
*/
float inputF (void)
{
    float f;

    printf("Enter a temperature in Fahrenheit: \t\t\t\t");
    scanf("%f", &f);
    return f;
}

/*  =================== convertCF ===================
           converts user input c to fahrenheit
       Pre:         ipC contains user input celsius
       Post:        value returned to convertedC
*/
float convertCF (float ipC)
{
   return (ipC * (9.0/5.0) + 32);
}

/* ====================  convertFC ====================
            converts user input f to celsius
       Pre:         ipF contains user input fahrenheit
       Post:        value returned to convertedF
*/
float convertFC (float ipF)
{
    return ((ipF - 32) * (5.0/9.0));
}

/* ====================  printCel ====================
         prints user input and converted temp
       Pre:        user input and converted value
       Post:       void
*/
void  printCel (float ipC, float cnvtdC)
{
    printf("\n\n\t\t\t%.2f degrees C = %.2f degrees F", ipC, cnvtdC);
    return;
}

/* ====================  printFah ====================
        prints user input and converted temp
       Pre:        user input and converted value
       Post:       void
*/
void  printFah (float ipF, float cnvtdF)
{
    printf("\n\n\t\t\t%.2f degrees F = %.2f degrees C", ipF, cnvtdF);
    return;
}
