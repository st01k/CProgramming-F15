/*	Calculates the total sale given the unit price, 
	quantity, discount, and tax rate.
	   Written by:
	   Date:
*/
#include <stdio.h>

#define TAX_RATE 8.50

int main (void)
{
//	Local Declarations 
	int    quantity;

	float  discountRate; 
	float  discountAm; 
	float  unitPrice;
	float  subTotal; 
	float  subTaxable;
	float  taxAm; 
	float  total; 

//	Statements 
	printf("\nEnter number of items sold:         ");
	scanf("%d", &quantity);

	printf("Enter the unit price:               ");
	scanf("%f", &unitPrice);

	printf("Enter the discount rate (per cent): ");
	scanf("%f", &discountRate);

	subTotal    = quantity * unitPrice;
	discountAm  = subTotal * discountRate / 100.0;
	subTaxable  = subTotal - discountAm;
	taxAm = subTaxable * TAX_RATE/ 100.00;
	total = subTaxable + taxAm;

	printf("\nQuantity sold:       %6d\n", quantity);
	printf("Unit Price of items: %9.2f\n", unitPrice);
	printf("                     ------------\n");

	printf("Subtotal :           %9.2f\n", subTotal);
	printf("Discount:           -%9.2f\n", discountAm);
	printf("Discounted total:    %9.2f\n", subTaxable);
	printf("Sales tax:          +%9.2f\n", taxAm);
	printf("Total sale:          %9.2f\n", total);

	return 0;
}	// main 

/*	Results:
Enter number of items sold:         34
Enter the unit price:               12.89
Enter the discount rate (per cent): 7

Quantity sold:           34
Unit Price of items:     12.89
                     ------------
Subtotal :              438.26
Discount:           -    30.68
Discounted total:       407.58
Sales tax:          +    34.64
Total sale:             442.23
*/