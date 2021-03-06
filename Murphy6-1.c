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
#include <math.h>                                                    //for exponent usage

#define MO_P_YR 12.00

//function declarations
void getInfo    (float*  loan, float* iRate, int*    years);        //gets user input
void calcMoPay  (float   loan, float  iRate, int     years,
                 double* mPay, int*   nMon,  double* mInt);         //calculates monthly payment
void printInfo  (float   loan, float  iRate, int     years,
                 double  mPay, int    nMon,  double  mInt);         //prints loan info summary
void printTab   (float   loan, double mPay,
                 int     nMon, double mInt);                        //prints payment table


int main()
{
    float loanAmt;                                                  //amount of loan - user input
    float yrInt;                                                    //yearly interest, percent - user input
    int   yrAmt;                                                    //number of years financed - user input

    getInfo     (&loanAmt, &yrInt, &yrAmt);

    double   mPayment;                                              //monthly payment - calculated
    double   monInt;                                                //monthly interest rate - percent
    int      numMon;                                                //number of months based on year input

    calcMoPay (loanAmt,  yrInt,    yrAmt,  &mPayment, &numMon, &monInt);
    printInfo (loanAmt,  yrInt,    yrAmt,  mPayment,  numMon,  monInt);
    printTab  (loanAmt,  mPayment, numMon, monInt);

    return 0;
}//main

//---------------------------------------------------------------------------------------
// gets user input, passes input values to main
void getInfo     (float* loan, float* iRate, int* years)
{
    printf ("\nAmount of loan (principal):\t");
    scanf  ("%f", loan);
    printf ("\nYearly interest rate (percent):\t");
    scanf  ("%f", iRate);
    printf ("\nNumber of years to finance:\t");
    scanf  ("%d", years);

    return;
}
//---------------------------------------------------------------------------------------
// calculates monthly payments, interest rate and number of months, passes them to main
void calcMoPay  (float   loan, float iRate, int     years,
                 double* mPay, int*  nMon,  double* mInt)
{
    double valP;                                                  //interim calculation holder
    double valQ;                                                  //interim calculation holder

    *nMon =    (years * MO_P_YR);
    *mInt =    (iRate / MO_P_YR) / 100.00;
     valP = pow((1.00 + *mInt), *nMon);
     valQ =    (valP / (valP - 1.00));
    *mPay =    (loan * *mInt * valQ);

    return;
}
//---------------------------------------------------------------------------------------
// prints information summary
void printInfo  (float  loan, float iRate, int    years,
                 double mPay, int   nMon,  double mInt)
{
    printf ("\n------------------------------------------------------\n\n"                   );
    printf ("Loan Amount (principal): \t$%.2f\n\n", loan                                     );
    printf ("Interest rate per year : \t%.2f%\n\n", iRate                                    );
    printf ("Interest rate per month: \t%.6f%\n\n", mInt, mInt                               );
    printf ("Number of years financed:\t%.2d\n\n",  years                                    );
    printf ("Number of months financed:\t%.3d\n\n", nMon                                     );
    printf ("Monthly Payment: \t\t$%.2f",           mPay                                     );
    printf ("\n\n-------------------------------------------------------------------------\n");

    return;
}
//---------------------------------------------------------------------------------------
// print table with loop
void printTab   (float loan, double mPay,
                 int   nMon, double mInt)
{
    double intPaid;                                                 //interest paid
    double prinPaid;                                                //principal paid
    double oldBal;                                                  //old balance
    double newBal;                                                  //new balance
    double totPaid;                                                 //total paid
    double tempMPay;                                                //temp holder in case monthly payment changes
    int    mCount;                                                  //month counter

    //print header
    printf ("\t   Old\t       Monthly      Interest      Principal       New\n"            );
    printf ("Month    Balance       Payment        Paid          Paid        Balance\n"    );
    printf ("-------------------------------------------------------------------------\n\n");

    //pre-loop initializations
    oldBal   = loan;
    intPaid  = loan * mInt;
    prinPaid = mPay - intPaid;
    tempMPay = mPay;
    newBal   = loan - prinPaid;
    totPaid  = 0.0;
    mCount   = 1;                                                   //to start at month 1

    //loop to print table data
    do
    {
        printf ("%2d    $%9.2f    $%9.2f    $%9.2f    $%9.2f    $%9.2f\n\n"
                , mCount, oldBal, tempMPay, intPaid, prinPaid, newBal);

        oldBal    = newBal;                                         //old balance becomes new balance
        intPaid   = newBal   * mInt;                                //new balance times monthly interest rate
        prinPaid  = tempMPay - intPaid;                             //old monthly payment minus new interest paid
        tempMPay  = prinPaid + intPaid;                             //new principal paid plus new interest paid
        newBal    = oldBal   - prinPaid;                            //new old balance minus new principal paid
        totPaid  += tempMPay;                                       //total plus monthly payment for that month
    }
    while (mCount++, mCount <= nMon);                               //inc counter, check months not exceeded

    //print total and footer
    printf ("-------------------------------------------------------------------------\n"  );
    printf ("                  Total Amount Paid:       $%9.2f\n", totPaid                 );
    printf ("-------------------------------------------------------------------------\n"  );
    printf ("NOTE: The last payment amount as a negative zero balance is the result \n"    );
    printf ("      of rounding errors that amount to no more or less than $0.01.\n"        );
    printf ("      This does not apply if the end balance reads exactly $0.00\n"           );
    printf ("-------------------------------------------------------------------------\n\n");

    return;
}

/* OUTPUT:
----------

1) example

Amount of loan (principal):     5000

Yearly interest rate (percent): 11

Number of years to finance:     1

------------------------------------------------------

Loan Amount (principal):        $5000.00

Interest rate per year :        11.00%

Interest rate per month:        0.009167%

Number of years financed:       01

Number of months financed:      012

Monthly Payment:                $441.91

-------------------------------------------------------------------------
           Old         Monthly      Interest      Principal       New
Month    Balance       Payment        Paid          Paid        Balance
-------------------------------------------------------------------------

 1    $  5000.00    $   441.91    $    45.83    $   396.07    $  4603.93

 2    $  4603.93    $   441.91    $    42.20    $   399.71    $  4204.22

 3    $  4204.22    $   441.91    $    38.54    $   403.37    $  3800.85

 4    $  3800.85    $   441.91    $    34.84    $   407.07    $  3393.78

 5    $  3393.78    $   441.91    $    31.11    $   410.80    $  2982.98

 6    $  2982.98    $   441.91    $    27.34    $   414.56    $  2568.42

 7    $  2568.42    $   441.91    $    23.54    $   418.36    $  2150.06

 8    $  2150.06    $   441.91    $    19.71    $   422.20    $  1727.86

 9    $  1727.86    $   441.91    $    15.84    $   426.07    $  1301.79

10    $  1301.79    $   441.91    $    11.93    $   429.98    $   871.81

11    $   871.81    $   441.91    $     7.99    $   433.92    $   437.89

12    $   437.89    $   441.91    $     4.01    $   437.89    $     0.00

-------------------------------------------------------------------------
                  Total Amount Paid:       $  5302.90
-------------------------------------------------------------------------
NOTE: The last payment amount as a negative zero balance is the result
      of rounding errors that amount to no more or less than $0.01.
      This does not apply if the end balance reads exactly $0.00
-------------------------------------------------------------------------

2) set 1

Amount of loan (principal):     10000

Yearly interest rate (percent): 12

Number of years to finance:     1

------------------------------------------------------

Loan Amount (principal):        $10000.00

Interest rate per year :        12.00%

Interest rate per month:        0.010000%

Number of years financed:       01

Number of months financed:      012

Monthly Payment:                $888.49

-------------------------------------------------------------------------
           Old         Monthly      Interest      Principal       New
Month    Balance       Payment        Paid          Paid        Balance
-------------------------------------------------------------------------

 1    $ 10000.00    $   888.49    $   100.00    $   788.49    $  9211.51

 2    $  9211.51    $   888.49    $    92.12    $   796.37    $  8415.14

 3    $  8415.14    $   888.49    $    84.15    $   804.34    $  7610.80

 4    $  7610.80    $   888.49    $    76.11    $   812.38    $  6798.42

 5    $  6798.42    $   888.49    $    67.98    $   820.50    $  5977.92

 6    $  5977.92    $   888.49    $    59.78    $   828.71    $  5149.21

 7    $  5149.21    $   888.49    $    51.49    $   837.00    $  4312.21

 8    $  4312.21    $   888.49    $    43.12    $   845.37    $  3466.85

 9    $  3466.85    $   888.49    $    34.67    $   853.82    $  2613.03

10    $  2613.03    $   888.49    $    26.13    $   862.36    $  1750.67

11    $  1750.67    $   888.49    $    17.51    $   870.98    $   879.69

12    $   879.69    $   888.49    $     8.80    $   879.69    $     0.00

-------------------------------------------------------------------------
                  Total Amount Paid:       $ 10661.85
-------------------------------------------------------------------------
NOTE: The last payment amount as a negative zero balance is the result
      of rounding errors that amount to no more or less than $0.01.
      This does not apply if the end balance reads exactly $0.00
-------------------------------------------------------------------------

3) set 2

Amount of loan (principal):     5000

Yearly interest rate (percent): 10

Number of years to finance:     2

------------------------------------------------------

Loan Amount (principal):        $5000.00

Interest rate per year :        10.00%

Interest rate per month:        0.008333%

Number of years financed:       02

Number of months financed:      024

Monthly Payment:                $230.72

-------------------------------------------------------------------------
           Old         Monthly      Interest      Principal       New
Month    Balance       Payment        Paid          Paid        Balance
-------------------------------------------------------------------------

 1    $  5000.00    $   230.72    $    41.67    $   189.06    $  4810.94

 2    $  4810.94    $   230.72    $    40.09    $   190.63    $  4620.31

 3    $  4620.31    $   230.72    $    38.50    $   192.22    $  4428.09

 4    $  4428.09    $   230.72    $    36.90    $   193.82    $  4234.26

 5    $  4234.26    $   230.72    $    35.29    $   195.44    $  4038.82

 6    $  4038.82    $   230.72    $    33.66    $   197.07    $  3841.76

 7    $  3841.76    $   230.72    $    32.01    $   198.71    $  3643.05

 8    $  3643.05    $   230.72    $    30.36    $   200.37    $  3442.68

 9    $  3442.68    $   230.72    $    28.69    $   202.04    $  3240.64

10    $  3240.64    $   230.72    $    27.01    $   203.72    $  3036.92

11    $  3036.92    $   230.72    $    25.31    $   205.42    $  2831.51

12    $  2831.51    $   230.72    $    23.60    $   207.13    $  2624.38

13    $  2624.38    $   230.72    $    21.87    $   208.85    $  2415.52

14    $  2415.52    $   230.72    $    20.13    $   210.60    $  2204.93

15    $  2204.93    $   230.72    $    18.37    $   212.35    $  1992.58

16    $  1992.58    $   230.72    $    16.60    $   214.12    $  1778.46

17    $  1778.46    $   230.72    $    14.82    $   215.90    $  1562.56

18    $  1562.56    $   230.72    $    13.02    $   217.70    $  1344.85

19    $  1344.85    $   230.72    $    11.21    $   219.52    $  1125.33

20    $  1125.33    $   230.72    $     9.38    $   221.35    $   903.99

21    $   903.99    $   230.72    $     7.53    $   223.19    $   680.80

22    $   680.80    $   230.72    $     5.67    $   225.05    $   455.74

23    $   455.74    $   230.72    $     3.80    $   226.93    $   228.82

24    $   228.82    $   230.72    $     1.91    $   228.82    $    -0.00

-------------------------------------------------------------------------
                  Total Amount Paid:       $  5537.39
-------------------------------------------------------------------------
NOTE: The last payment amount as a negative zero balance is the result
      of rounding errors that amount to no more or less than $0.01.
      This does not apply if the end balance reads exactly $0.00
-------------------------------------------------------------------------

4) set 3

Amount of loan (principal):     1000

Yearly interest rate (percent): 8

Number of years to finance:     3

------------------------------------------------------

Loan Amount (principal):        $1000.00

Interest rate per year :        8.00%

Interest rate per month:        0.006667%

Number of years financed:       03

Number of months financed:      036

Monthly Payment:                $31.34

-------------------------------------------------------------------------
           Old         Monthly      Interest      Principal       New
Month    Balance       Payment        Paid          Paid        Balance
-------------------------------------------------------------------------

 1    $  1000.00    $    31.34    $     6.67    $    24.67    $   975.33

 2    $   975.33    $    31.34    $     6.50    $    24.83    $   950.50

 3    $   950.50    $    31.34    $     6.34    $    25.00    $   925.50

 4    $   925.50    $    31.34    $     6.17    $    25.17    $   900.33

 5    $   900.33    $    31.34    $     6.00    $    25.33    $   875.00

 6    $   875.00    $    31.34    $     5.83    $    25.50    $   849.49

 7    $   849.49    $    31.34    $     5.66    $    25.67    $   823.82

 8    $   823.82    $    31.34    $     5.49    $    25.84    $   797.98

 9    $   797.98    $    31.34    $     5.32    $    26.02    $   771.96

10    $   771.96    $    31.34    $     5.15    $    26.19    $   745.77

11    $   745.77    $    31.34    $     4.97    $    26.36    $   719.40

12    $   719.40    $    31.34    $     4.80    $    26.54    $   692.86

13    $   692.86    $    31.34    $     4.62    $    26.72    $   666.15

14    $   666.15    $    31.34    $     4.44    $    26.90    $   639.25

15    $   639.25    $    31.34    $     4.26    $    27.07    $   612.18

16    $   612.18    $    31.34    $     4.08    $    27.26    $   584.92

17    $   584.92    $    31.34    $     3.90    $    27.44    $   557.48

18    $   557.48    $    31.34    $     3.72    $    27.62    $   529.86

19    $   529.86    $    31.34    $     3.53    $    27.80    $   502.06

20    $   502.06    $    31.34    $     3.35    $    27.99    $   474.07

21    $   474.07    $    31.34    $     3.16    $    28.18    $   445.90

22    $   445.90    $    31.34    $     2.97    $    28.36    $   417.53

23    $   417.53    $    31.34    $     2.78    $    28.55    $   388.98

24    $   388.98    $    31.34    $     2.59    $    28.74    $   360.24

25    $   360.24    $    31.34    $     2.40    $    28.93    $   331.30

26    $   331.30    $    31.34    $     2.21    $    29.13    $   302.17

27    $   302.17    $    31.34    $     2.01    $    29.32    $   272.85

28    $   272.85    $    31.34    $     1.82    $    29.52    $   243.33

29    $   243.33    $    31.34    $     1.62    $    29.71    $   213.62

30    $   213.62    $    31.34    $     1.42    $    29.91    $   183.71

31    $   183.71    $    31.34    $     1.22    $    30.11    $   153.60

32    $   153.60    $    31.34    $     1.02    $    30.31    $   123.28

33    $   123.28    $    31.34    $     0.82    $    30.51    $    92.77

34    $    92.77    $    31.34    $     0.62    $    30.72    $    62.05

35    $    62.05    $    31.34    $     0.41    $    30.92    $    31.13

36    $    31.13    $    31.34    $     0.21    $    31.13    $    -0.00

-------------------------------------------------------------------------
                  Total Amount Paid:       $  1128.11
-------------------------------------------------------------------------
NOTE: The last payment amount as a negative zero balance is the result
      of rounding errors that amount to no more or less than $0.01.
      This does not apply if the end balance reads exactly $0.00
-------------------------------------------------------------------------
*/
