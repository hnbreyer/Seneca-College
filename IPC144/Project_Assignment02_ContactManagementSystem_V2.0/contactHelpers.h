/*----------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks.
----------------------------------------------------------------------*/


//  This header file now has functions with parameters referring to 
//  the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"

//--------------------------------
// Function Prototypes
//--------------------------------


void clearKeyboard(void);                                                                // Clear the standard input buffer

void pause(void);

int getInt(void);

int getIntInRange(int min, int max);

int yes(void);

int menu(void);

void contactManagerSystem(void);

void getTenDigitPhone(char phoneNum[]);                                                // Generic function to get a ten-digit phone number

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

void displayContactHeader(void);

void displayContactFooter(int count);

void displayContact(const struct Contact* contact);

void displayContacts(const struct Contact contacts[], int size);

void searchContacts(const struct Contact contacts[], int size);

void addContact(struct Contact contacts[], int size);

void updateContact(struct Contact contacts[], int size);

void deleteContact(struct Contact contacts[], int size);

void sortContacts(struct Contact contacts[], int size);
