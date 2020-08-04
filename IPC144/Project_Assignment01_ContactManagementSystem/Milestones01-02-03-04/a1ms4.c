#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
    // Declare variables here:

    // Create a variable of type Contact and call it something self-describing like "contact"
    // - HINT: Be sure to initialize the values to 0 and empty C strings
    // IMPORTANT:  Do NOT declare variables of type Name, Address, or Numbers

	struct Contact contacts =  {{{0}}} ;
		

    // Display the title
	printf("Contact Management System\n");
	printf("=========================\n");

    // Call the Contact function getName to store the values for the Name member
	getName(&contacts.name);

    // Call the Contact function getAddress to store the values for the Address member
	getAddress(&contacts.address);

    // Call the Contact function getNumbers to store the values for the Numbers member
	getNumbers(&contacts.numbers);

    // Display Contact summary details

	printf("Contact Details\n");
	printf("===============\n");
	printf("Name Details\n");
	printf("------------\n");
	printf("First name: %s\n", contacts.name.firstName);
	printf("Middle initial(s): %s\n", contacts.name.middleInitial);
	printf("Last name: %s\n", contacts.name.lastName);
	printf("\n");
	printf("Address Details\n");
	printf("---------------\n");
	printf("Street number: %u\n", contacts.address.streetNumber);
	printf("Street name: %s\n", contacts.address.street);
	printf("Apartment: %u\n", contacts.address.apartmentNumber);
	printf("Postal code: %s\n", contacts.address.postalCode);
	printf("City: %s\n", contacts.address.city);
	printf("\n");
	printf("Phone Numbers\n");
	printf("-------------\n");
	printf("Cell phone number: %s\n", contacts.numbers.cell);
	printf("Home phone number: %s\n", contacts.numbers.home);
	printf("Business phone number: %s\n", contacts.numbers.business);
	printf("\n");

    // Display Completion Message
    printf("Structure test for Contact using functions done!\n");
    
    return 0;
}

/* OUTPUT:

Contact Management System
=========================
Please enter the contact's first name: Wilma Dee
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): N. O.
Please enter the contact's last name: Flint Rubble
Please enter the contact's street number: 30
Please enter the contact's street name: Bedrock St.
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 12
Please enter the contact's postal code: Z8Z 7R7
Please enter the contact's city: North York
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 9992223333
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 8881112222
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 3337779999

Contact Details
===============
Name Details
------------
First name: Wilma Dee
Middle initial(s): N. O.
Last name: Flint Rubble

Address Details
---------------
Street number: 30
Street name: Bedrock St.
Apartment: 12
Postal code: Z8Z 7R7
City: North York

Phone Numbers
-------------
Cell phone number: 9992223333
Home phone number: 8881112222
Business phone number: 3337779999

Structure test for Contact using functions done!
*/
