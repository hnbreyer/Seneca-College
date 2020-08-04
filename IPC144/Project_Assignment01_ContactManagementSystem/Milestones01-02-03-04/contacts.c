#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *name) {
	char choice = 0;
	printf("Please enter the contact's first name: ");
	scanf("%[^\n]", name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &choice); //space before the % sign; it makes sure
		//the buffer is empty to receive data from user

	if (choice == 'y' || choice == 'Y') { //selection code block, so user can chose to enter data or not
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", name->middleInitial); //scanf_s("%[^\n]"); it accepts strings with space between words, until a new line is encountered  
		
	}
	
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", name->lastName);

}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* address) {

	char choice = 0;

	printf("Please enter the contact's street number: ");
	scanf("%u", &address->streetNumber); //%u specifier for unsigned int 

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


// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* numbers) {

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
