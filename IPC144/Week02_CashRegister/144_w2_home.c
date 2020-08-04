#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include <stdio.h>
int main(void)                                                            //main command; initiates the code
{
	double amount;
	float gst;
	double amountOwing;
	int loonies;
	int balance;
	int quarters;
	int dimes;
	int nickels;
	int pennies;

	printf("Please enter the amount to be paid: $");                 //printf to ask user entry
	scanf("%lf", &amount);                                           // scanf_s to accept user entry

	amountOwing = amount;                      
	gst = amountOwing * .13 + .005;                                 //calculating the tax and rounding up
	printf("GST: %.2f\n", gst);  

	amountOwing = amount + gst;                                     //adding the tax to the amount owed
	printf("Balance owing: $%.2lf\n",amountOwing);

	loonies = amountOwing;                                         // "loonies" is an int, the decimals are ignored and only the first number is read
	amountOwing = amountOwing - loonies;                           // subtract loonies from amount owed
	
	printf("Loonies required: %d, ", loonies);                     //shows how many loonies are required
	printf("balance owing $%.2f\n", amountOwing);                 //shows balance owing; .2f% to show only 2 decimals; \n for new line
	
	balance = amountOwing * 100;                                  //multiplying by 100, so we can work with int

	quarters = balance / 25;                                      //calculates how many quarters are owed
	balance = balance % 25;                                       //mod to calculate the remainder
	
	printf("Quarters required: %d, ", quarters);                  //shows how many quarters are required
	printf("balance owing $%1.2f\n", (float)balance / 100);       //shows final balance owing; .2f% to show only 2 decimals; \n for new line

	dimes = balance / 10; 
	balance = balance % 10;

	printf("Dimes required: %d, ", dimes);
	printf("balance owing $%1.2f\n", (float)balance / 100);

	nickels = balance / 5;
	balance = balance % 5;

	printf("Nickels required: %d, ", nickels);
	printf("balance owing $%1.2f\n", (float)balance / 100);

	pennies = balance;
	balance = 0;

	printf("Pennies required: %d, ", pennies);
	printf("balance owing $%1.2f\n", (float)balance / 100);

	return 0;                                                      //program finished

}

/*OUTPUT
Please enter the amount to be paid: $8.68
GST: 1.13
Balance owing: $9.81
Loonies required: 9, balance owing $0.81
Quarters required: 3, balance owing $0.06
Dimes required: 0, balance owing $0.06
Nickels required: 1, balance owing $0.01
Pennies required: 1, balance owing $0.00
*/
