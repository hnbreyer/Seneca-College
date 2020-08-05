#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "contacts.h"
#include "contactHelpers.h"

void getName(struct Name* name) {
	char choice = 0;

	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	choice = yes();

	if (choice == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", name->middleInitial); 

	}
	else {
		name->middleInitial[0] = '\0';
	}
	//clearKeyboard(); 

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", name->lastName);
}

void getAddress(struct Address* address) {

	char choice = 0;

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();

	while (address->streetNumber < 0) {                                                  //added to accept only positive values
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		address->streetNumber = getInt();
	}

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	choice = yes();

	if (choice == 1) {
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		
	}
	
	while (address->apartmentNumber < 0) {
		printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
		address->apartmentNumber = getInt();
	}
	

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", address->city);

}
	

	void getNumbers(struct Numbers* numbers) {

		char choice = 0;

		printf("Please enter the contact's cell phone number: ");
		getTenDigitPhone(numbers->cell);
		
		printf("Do you want to enter a home phone number? (y or n): ");
		choice = yes();

		if (choice == 1) {
			printf("Please enter the contact's home phone number: ");
			getTenDigitPhone(numbers->home);
		}
		else {
			numbers->home[0] = '\0';
		}

		printf("Do you want to enter a business phone number? (y or n): ");
		choice = yes();

		if (choice == 1) {
			printf("Please enter the contact's business phone number: ");
			getTenDigitPhone(numbers->business);
		}
		else {
			numbers->business[0] = '\0';
		}
		
	}

	void getContact(struct Contact* contacts) {

		getName(&(*contacts).name);
		getAddress(&(*contacts).address);
		getNumbers(&(*contacts).numbers);

	}
