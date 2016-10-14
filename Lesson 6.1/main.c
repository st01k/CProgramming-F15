/*
*****************************************************************************************************************
*                                 Name:            Monthly Payment Calculator                                   *
*                                 Version:         1.1                                                          *
*                                 Chapter:         6, Assignment 6.1                                            *
*                                 Author:          Casey Murphy                                                 *
*                                 Date Created:    28 Sep 15                                                    *
*                                 Last Modified:   30 Sep 15                                                    *
* ------------------------------------------------------------------------------------------------------------- *
*                       Calculates monthly payments for a loan based on user input                              *
*****************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>                                                   //for exponent usage

#define MO_P_YR 12.00

//function declarations
void getInfo    (float*  loan, float*  iRate, int*    years);        //gets user input
void calcMoPay  (float*  loan, float*  iRate, int*    years,
                 double* mPay, int*    nMon,  double* mInt);         //calculates monthly payment
void printInfo  (float*  loan, float*  iRate, int*    years,
                 double* mPay, int*    nMon,  double* mInt);         //prints loan info summary
void printTab   (float*  loan, double*  mPay,
                 int*    nMon, double* mInt);                        //prints payment table


int main()
{
    float   loanAmt;                                                //amount of loan - user input
    float   yrInt;                                                  //yearly interest, percent - user input
    int     yrAmt;                                                  //number of years financed - user input

    getInfo     (&loanAmt, &yrInt, &yrAmt);

    double   mPayment;                                              //monthly payment - calculated
    double   monInt;                                                //monthly interest rate - percent
    int      numMon;                                                //number of months based on year input

    calcMoPay   (&loanAmt,  &yrInt,    &yrAmt,  &mPayment, &numMon,   &monInt);
    printInfo   (&loanAmt,  &yrInt,    &yrAmt,  &mPayment, &numMon,   &monInt);
    printTab    (&loanAmt,  &mPayment, &numMon, &monInt);

    return 0;
}//main

// gets user input, passes input values to main
void    getInfo     (float* loan, float* iRate, int* years)
{
    printf  ("\nAmount of loan (principal):\t");
    scanf   ("%f", loan);
    printf  ("\nYearly interest rate (percent):\t");
    scanf   ("%f", iRate);
    printf  ("\nNumber of years to finance:\t");
    scanf   ("%d", years);

    return;
}

// calculates monthly payments, interest rate and number of months, passes them to main
void calcMoPay  (float*  loan,  float* iRate, int*    years,
                 double*  mPay, int*   nMon,  double* mInt)
{
    double   valP;                                                  //interim calculation holder
    double   valQ;                                                  //interim calculation holder

    *nMon = (*years * MO_P_YR);
    *mInt = (*iRate / MO_P_YR) / 100.00;
    valP  = pow((1.00 + *mInt), *nMon);
    valQ  = (valP / (valP - 1.00));
    *mPay = (*loan * *mInt * valQ);

    return;
}

// prints information summary
void printInfo  (float*  loan, float* iRate, int*    years,
                 double* mPay, int*   nMon,  double* mInt)
{
    printf("\n------------------------------------------------------\n\n");
    printf("Loan Amount (principal): \t$%.2f\n\n", *loan);
    printf("Interest rate per year : \t%.2f%\n\n", *iRate);
    printf("Interest rate per month: \t%.6f%\n\n", *mInt, *mInt);
    printf("Number of years financed:\t%.2d\n\n", *years);
    printf("Number of months financed:\t%.3d\n\n", *nMon);
    printf("Monthly Payment: \t\t$%.2f", *mPay);
    printf("\n\n-------------------------------------------------------------------------\n");

    return;
}

// print table with loop
void printTab   (float* loan, double*  mPay,
                 int*   nMon, double* mInt)
{
    double intPaid;
    double prinPaid;
    double oldBal;
    double newBal;
    double totPaid;
    double tempMPay;
    int   i;

    printf("\t   Old\t       Monthly      Interest      Principal       New\n");
    printf ("Month    Balance       Payment        Paid          Paid        Balance\n");
    printf("-------------------------------------------------------------------------\n\n");

    //initializations
    oldBal   = *loan;
    intPaid  = *loan * *mInt;
    prinPaid = *mPay - intPaid;
    newBal   = *loan - prinPaid;
    tempMPay = *mPay;
    totPaid  =  0.0;
    i        =  1;

    do
    {
        if (newBal <= tempMPay)
            tempMPay = prinPaid + intPaid;

        printf ("%2d    $%9.2f    $%9.2f    $%9.2f    $%9.2f    $%9.2f\n\n", i, oldBal, tempMPay, intPaid, prinPaid, newBal);

        oldBal    = newBal;
        intPaid   = oldBal * *mInt;
        prinPaid  = tempMPay - intPaid;
        newBal    = oldBal - prinPaid;
        totPaid  += tempMPay;
    }
    while (i++, i <= *nMon);

    printf("-------------------------------------------------------------------------\n");
    printf ("                  Total Amount Paid:       $%9.2f\n", totPaid);
    printf("-------------------------------------------------------------------------\n");
    printf("NOTE: The last payment amount as a negative zero balance is the result \n");
    printf("      of rounding errors that amount to no more or less than $0.01.\n");
    printf("      This does not apply if the end balance reads exactly $0.00\n");
    printf("-------------------------------------------------------------------------\n\n");
    return;
}
