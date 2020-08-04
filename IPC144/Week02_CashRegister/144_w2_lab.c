#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include <stdio.h>
int main(void)
{
	double amount;
	int loonies;
	float balance;
	int quarters;
	float final_balance;

	printf("Please enter the amount to be paid: $"); //printf to ask user entry
	scanf("%lf", &amount);                           // scanf_s to accept user entry

	loonies = amount;                                // "loonies" is an int, the decimals are ignored and only the first number is read
	balance = amount - loonies;                      // subtract loonies from amount owed
	quarters = balance / 0.25;                       //calculates how many quarters are owed
	final_balance = balance - (quarters*0.25);       //calculates final balance

	printf("Loonies required: %d, ", loonies);      //shows how many loonies are required
	printf("balance owing $%.2f\n", balance);       //shows balance owing; .2f% to show only 2 decimals; \n for new line
	printf("Quarters required: %d, ", quarters);    //shows how many quarters are required
	printf("balance owing $%.2f\n", final_balance); //shows final balance owing; .2f% to show only 2 decimals; \n for new line


	return 0;
}

/*OUTPUT
Please enter the amount to be paid: $8.68
Loonies required: 8, balance owing $0.68
Quarters required: 2, balance owing $0.18
*/
