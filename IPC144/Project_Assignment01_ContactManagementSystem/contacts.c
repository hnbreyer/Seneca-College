#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contacts.h"

void getName(struct Name *name) {                                                       // Get and store from standard input the values for Name
	char choice = 0;
	printf("Please enter the contact's first name: ");
	scanf("%[^\n]", name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &choice);                                                          //space before the % sign; it makes sure
		                                                                        //the buffer is empty to receive data from user

	if (choice == 'y' || choice == 'Y') {                                           //selection code block, user can chose to enter data or not
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", name->middleInitial);                                  //it accepts strings w/ space bet. words until new line  
		
	}
	
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", name->lastName);

}

void getAddress(struct Address* address) {                                             // Get and store from standard input the values for Address

	char choice = 0;

	printf("Please enter the contact's street number: ");
	scanf("%u", &address->streetNumber);                                           //%u specifier for unsigned int 

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%u", &address->apartmentNumber);
	}


	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", address->city);
}


void getNumbers(struct Numbers* numbers) {                                        // Get and store from standard input the values for Numbers

	char choice = 0;

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %s", numbers->cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &choice);

	if (choice == 'Y' || choice == 'y') {
		printf("Please enter the contact's home phone number: ");
		scanf(" %s", numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf(" %s", numbers->business);
	}
	printf("\n");

}
