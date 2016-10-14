/*	Calculate the tax due or the refund for a family based
	on the following imaginary formula.
	1. For each dependent deduct $1,000 from income.
	2. Determine tax rate from the following brackets:
	       bracket    taxable income       tax rate
	          1             <= 10000           2%
	          2        10001 - 20000           5%
	          3        20001 - 30000           7%
	          4        30001 - 50000          10%
	          5        50001 and up           15%
	Then print the amount of tax or the refund.

	   Written by: 
	   Date: 
*/
#include <stdio.h>

#define LOWEST  0000000.00
#define HIGHEST 1000000.00

#define LIMIT1    10000.00
#define LIMIT2    20000.00
#define LIMIT3    30000.00
#define LIMIT4    50000.00

#define RATE1 02
#define RATE2 05
#define RATE3 07
#define RATE4 10
#define RATE5 15

#define DEDN_PER_DPNDNT 1000

//	Function Declarations 
void getData   (double* totalIncome, double* taxPaid,
                int*    numOfDpndnts);

void calcTaxes (double  totalIncome, 
                double  taxPaid,
                int     numOfDpndnts,
                double* taxableIncome,
                double* totalTax, 
                double* taxDue);

void printInformation (double totalIncome,
                       double taxPaid, 
                       int    numOfDpndnts, 
                       double totalTax,
                       double paidTax,
                       double taxDue);

double bracketTax (double income,
                   double startLimit,
                   double stopLimit,
                   int    rate);

int main (void)
{
//	Local Declarations
	int    numOfDpndnts;
	double taxDue;
	double taxPaid;
	double totalIncome;
	double taxableIncome;
	double totalTax;

//	Statements 
	getData   (&totalIncome,  &taxPaid, &numOfDpndnts);
	calcTaxes (totalIncome,    taxPaid,  numOfDpndnts,
	          &taxableIncome, &totalTax, &taxDue);
	printInformation (totalIncome,  taxableIncome,
	                  numOfDpndnts, totalTax,
	                  taxPaid,      taxDue);
	return 0;
}	// main 

/*	=================== getData ================== 
	This function reads tax data from the keyboard.
	   Pre  Nothing
	   Post Reads totalIncome, taxPaid, & numOfDpndnts
*/
void getData ( double* totalIncome, double* taxPaid,
               int*    numOfDpndnts)
{
//	Statements 
	printf("Enter your total income for last year: ");
	scanf ("%lf", totalIncome);

	printf("Enter total of payroll deductions    : ");
	scanf ("%lf", taxPaid);

	printf("Enter the number of dependents       : ");
	scanf ("%d", numOfDpndnts);
	return;
}	// getData

/*	================= calcTaxes ================= 
	This function calculates the taxes due.
	   Pre  Given-income, numOfDpndnts, & taxPaid
	   Post Tax income, total tax, and tax due
	        calculated
*/
void calcTaxes (double  totInc, 
                double  taxPaid, 
                int     numOfDpndnts, 
                double* taxableInc,
                double* totTax, 
                double* taxDue) 
{
//	Statements 
	*taxableInc = totInc - 
	                (numOfDpndnts* DEDN_PER_DPNDNT);
	*totTax = 
	    bracketTax(*taxableInc, LOWEST, LIMIT1,  RATE1)
	  + bracketTax(*taxableInc, LIMIT1, LIMIT2,  RATE2)
	  + bracketTax(*taxableInc, LIMIT2, LIMIT3,  RATE3)
	  + bracketTax(*taxableInc, LIMIT3, LIMIT4,  RATE4)
	  + bracketTax(*taxableInc, LIMIT4, HIGHEST, RATE5);

	*taxDue = *totTax - taxPaid;
	return;
}	// calcTaxes 

/*	================= printInformation =================
	This function prints a table showing all information.
	   Pre  The parameter list
	   Post Prints the table
*/
void printInformation (double totalIncome, 
                       double income, 
                       int    numDpndnts, 
                       double totalTax, 
                       double paidTax, 
                       double dueTax) 
{
//	Statements 
	printf("\nTotal income          :%10.2f\n", 
	       totalIncome);
	printf("Number of dependents  :%7d\n",    numDpndnts);
	printf("Taxable income        :%10.2f\n", income);
	printf("Total tax             :%10.2f\n", totalTax);
	printf("Tax already paid      :%10.2f\n", paidTax);

	if (dueTax >= 0.0)
	    printf("Tax due               :%10.2f\n", dueTax);
	else
	    printf("Refund                :%10.2f\n", -dueTax);
	return;
}	// printInformation 

/*	================== bracketTax ================== 
	Calculates the tax for a particular bracket.
	   Pre    The taxableIncome
	   Post   Returns the tax for a particular bracket
*/
double bracketTax (double income,    double startLimit,
                   double stopLimit, int    rate)
{ 
//	Local Declarations 
	double tax;

//	Statements 
	if (income <= startLimit)
	    tax = 0.0;
	else
	    if (income > startLimit && income <= stopLimit) 
	        tax = (income - startLimit) * rate / 100.00;
	    else
	        tax = (stopLimit - startLimit) * rate / 100.00;

	return tax;
}	// bracketTax 

/*	Results
	Enter your total income for last year: 15000
	Enter total of payroll deductions    : 250
	Enter the number of dependents       : 2

	Total income          :  15000.00
	Number of dependents  :      2
	Taxable income        :  13000.00
	Total tax             :    350.00
	Tax already paid      :    250.00
	Tax due               :    100.00
*/