/*
************************************************************
*               Inch and Degree Converter                  *
*               Chapter 3, Assignment 3.1                  *
*                 Author: Casey Murphy                     *
*                Date Created: 1 Sep 15                    *
*               Last Modified: 4 Sep 15                    *
*                                                          *
* Converts inches into feet, yards, centimeters and meters *
*  and degrees to and from celsius, fahrenheit, and kelvin *
************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    /* Local Declarations */
    char qInch; /* Question Inch Convert */
    char qDegree; /* Question Degree Convert */
    char degree_type; /* Celsius, Fahrenheit, Kelvin */
    float ip_inch; /* User Input Inches */
    float feet;
    float yard;
    float cm; /* Centimeters */
    float m; /* Meters */
    float ip_degree; /* User Input Degrees */
    float c; /* Degrees Celsius */
    float f; /* Degrees Fahrenheit */
    float k; /* Degrees Kelvin */

    /* Statements */
    printf("--------------------------------------------------------------------------\n\n");
    printf("Would you like to convert inches (Y/N)? ");
    scanf(" %c", &qInch);
    printf("\n--------------------------------------------------------------------------\n\n");

    /* Convert Inches */
    if (qInch == 'y' || qInch == 'Y')
    {
        printf("Enter the number of inches to convert: ");
        scanf("%f", &ip_inch);
        feet = ip_inch / 12;
        yard = ip_inch / 36;
        cm = ip_inch * 2.54;
        m = ip_inch / 39.37;
        printf("\nYou entered %10.3f inches.\n\n", ip_inch);
        printf("--------------------------------------------------------------------------\n\n");
        printf("That is equivalent to: \n\n");
        printf("%10.3f feet\n", feet);
        printf("%10.3f yards\n", yard);
        printf("%10.3f centimeters\n", cm);
        printf("%10.3f meters\n\n", m);
        printf("--------------------------------------------------------------------------\n\n");
    } /* End if */

    if (qInch != 'y' && qInch != 'Y' && qInch != 'n' && qInch != 'N')
    {
       printf("\nERROR 1: You have entered an invalid response.  Program terminating...");
       printf("\n\n--------------------------------------------------------------------------\n\n");
       return 1;
    } /* End if */

    printf("Would you like to convert degrees (Y/N)? ");
    scanf(" %c", &qDegree);
    printf("\n--------------------------------------------------------------------------\n\n");

    if (qDegree == 'n' || qDegree == 'N')
    {
        printf("Program completed successfully.  Terminating.");
        printf("\n\n--------------------------------------------------------------------------\n\n");
        return 0;
    } /* End if */

    if (qDegree != 'y' && qDegree != 'Y' && qDegree != 'n' && qDegree != 'N')
    {
        printf("\nERROR 2: You have entered an invalid response.  Program terminating...");
        printf("\n\n--------------------------------------------------------------------------\n\n");
        return 2;
    } /* End if */

    if (qDegree == 'y' || qDegree == 'Y')
    {
        printf("What temperature scale is your measurement in (C, F, K)? ");
        scanf(" %c", &degree_type);
        printf("\n--------------------------------------------------------------------------\n\n");
    } /* End if */

    if (degree_type != 'c' && degree_type != 'C' && degree_type != 'f' && degree_type != 'F' && degree_type != 'k' && degree_type != 'K')
    {
        printf("ERROR 3: You entered an invalid degree type.  Program terminating...");
        printf("\n\n--------------------------------------------------------------------------\n\n");
        return 3;
    } /* End if */

    printf("Enter the temperature you would like to convert: ");
    scanf("%f", &ip_degree);
    printf("\n\nYou entered: %10.3f %c.\n\n", ip_degree, degree_type);
    printf("--------------------------------------------------------------------------\n\n");

    /* Convert Celsius */
    if (degree_type == 'c' || degree_type == 'C')
    {
        f = ip_degree * (9.0/5.0) + 32;
        k = ip_degree + 273.15;
        printf("%10.3f C = %1.3f F = %1.3f K\n\n", ip_degree, f, k);
        printf("--------------------------------------------------------------------------\n\n");
    } /* End if */

    /* Convert Fahrenheit */
    if (degree_type == 'f' || degree_type == 'F')
    {
        c = (ip_degree - 32) * (5.0/9.0);
        k = (ip_degree + 459.67) * (5.0/9.0);
        printf("%10.3f F = %1.3f C = %1.3f K\n\n", ip_degree, c, k);
        printf("--------------------------------------------------------------------------\n\n");
    } /* End if */

    /* Convert Kelvin */
    if (degree_type == 'k' || degree_type == 'K')
    {
        c = ip_degree - 273.15;
        f = ip_degree * (9.0/5.0) - 459.67;
        printf("%10.3f K = %1.3f C = %1.3f F\n\n", ip_degree, c, f);
        printf("--------------------------------------------------------------------------\n\n");
    } /* End if */

    printf("Program completed successfully.  Terminating.");
    printf("\n\n--------------------------------------------------------------------------\n\n");
    return 0;
} /* End Main */
