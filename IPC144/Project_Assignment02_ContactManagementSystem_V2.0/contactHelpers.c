#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>
#include <ctype.h>                                                                      //included for the isdigit function

#include "contactHelpers.h"

#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

void clearKeyboard(void)
{
	while (getchar() != '\n');                                                      // empty execution code block on purpose
}

void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();                                                                // returns the control to caller when user presses Enter ('\n')
}

int getInt(void)
{
	char nl = 'x';
	int value;

	scanf(" %d%c", &value, &nl);
	while (nl != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf(" %d%c", &value, &nl);
	}
	return value;
}

int getIntInRange(int min, int max)
{
	int validInt = getInt();                                                      //assign the function to the variable, so the value entered will be stored there
	while (validInt < min || validInt > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		validInt = getInt();
	}
	return validInt;
}

int yes(void)
{

	char nl = 'x', validChar = 'x';
	int y;

	scanf(" %c%c", &validChar, &nl);

	while ((nl != '\n') && (!(validChar == 'Y') || (validChar == 'y') || (validChar == 'N') || (validChar == 'n')))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &validChar, &nl);
	}

	if ((validChar == 'Y') || (validChar == 'y'))
	{
		y = 1;
	}
	else if ((validChar == 'N') || (validChar == 'n'))
	{
		y = 0;
	}
	return y;
}

int menu(void)
{
	int option;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	option = getIntInRange(0, 6);                                                       //assigning values to the function

	return option;
	printf("\n");
}

void contactManagerSystem(void)
{
	int option;
	int choice = 0;
	struct Contact contacts[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
 {
	 { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
 {
	 { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
 {
	 { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};


	do {
		option = menu();

		switch (option)
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS),
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			choice = yes();
			if (choice == 1)
			{
				printf("\nContact Management System: terminated\n");

				return;

			}
			else {
				printf("\n");
			}

			break;
		}

	} while (option >= 0 || option <= 6);

	return;
}


void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", phoneNum);
		clearKeyboard();

		int i;
		int digitcheck = 0;
		for (i = 0; phoneNum[i] != '\0'; i++)                                      //modification to validate only numeric character digits
		{
			if (isdigit(phoneNum[i]) !=0)
			{
				digitcheck++;
			}
			else {
				digitcheck = 0;
			}
		}

		if (strlen(phoneNum) == 10 && digitcheck > 9)                             // (String Length Function: validate entry of 10 characters)

			needInput = 0;

		else

			printf("Enter a 10-digit phone number: ");
	}
}

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	for (i = 0; i < size; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			return i;
		}
	}
	return -1;
}

void displayContactHeader(void)
{
	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}

void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n",count);
}

void displayContact(const struct Contact* contact)
{
	//full name
	printf(" %s ", contact->name.firstName);                                            //spaces before and after format as per instructions
	if (strlen(contact->name.middleInitial) != 0)                                       //checking if middle name was entered by checking its length 
		printf("%s ", contact->name.middleInitial);
	printf("%s\n", contact->name.lastName);
	//numbers
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	//address
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
		printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

void displayContacts(const struct Contact contacts[], int size)
{
	displayContactHeader();
	int i;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) != 0)
		{
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

void searchContacts(const struct Contact contacts[], int size)
{
	int contactFound;
	char validCell[11];
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(validCell);
	contactFound = findContactIndex(contacts, size, validCell);
	if (contactFound == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
		
	}
	else {
		printf("\n");
		displayContact(&contacts[contactFound]);
		
	}
	printf("\n");
}

void addContact(struct Contact contacts[], int size)
{
	printf("\n");
	int i;

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			getContact(&contacts[i]);
			printf("--- New contact added! ---\n");
			printf("\n");
			break;
		}
		else if (i == size - 1)
		{
			printf("*** ERROR: The contact list is full! ***\n");
			printf("\n");
			break;
		}
	}
}

void updateContact(struct Contact contacts[], int size)
{
	printf("\n");

	char upnumber[11];
	int contactFound;
	char YorN;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(upnumber);
	contactFound = findContactIndex(contacts, size, upnumber);

	if (contactFound != -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[contactFound]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		YorN = yes();
		if (YorN == 1)
		{
			getName(&contacts[contactFound].name);
			
		}
		printf("Do you want to update the address? (y or n): ");
		YorN = yes();
		if (YorN == 1)
		{
			getAddress(&contacts[contactFound].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		YorN = yes();
		if (YorN == 1)
		{			
		getNumbers(&contacts[contactFound].numbers);
		
		}
		printf("--- Contact Updated! ---\n");
		printf("\n");
	 
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
	}
}

void deleteContact(struct Contact contacts[], int size)
{
	printf("\n");

	int foundContact;
	char delnumber[11];
	char YorN;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(delnumber);
	foundContact = findContactIndex(contacts, size, delnumber);

	if (foundContact != -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[foundContact]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		YorN = yes();
		
		if (YorN == 1)
		{
			contacts[foundContact].numbers.cell[0] = '\0';
			contacts[foundContact].numbers.home[0] = '\0';
			contacts[foundContact].numbers.business[0] = '\0';
			
			printf("--- Contact deleted! ---\n");
			
		}
		printf("\n");
	}
}

void sortContacts(struct Contact contacts[], int size)                                      //bubble sort
{
	struct Contact temp;
	int j, i;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[j].numbers.cell) != 0) {
				if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0) {
					temp = contacts[i];
					contacts[i] = contacts[j];
					contacts[j] = temp;
				}
			}
		}
	}

	printf("\n--- Contacts sorted! ---\n");
	printf("\n");
}
