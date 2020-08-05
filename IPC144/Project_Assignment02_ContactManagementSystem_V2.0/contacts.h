#ifndef CONTACTS_H_                                                           //safeguards - ensure only one copy of header file
#define CONTACTS_H_                                                           //is included when compiling

//--------------------------------
// Structure Types
//--------------------------------

struct Name                                                                  // Structure type Name declaration
{
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

struct Address                                                              // Structure type Address declaration
{
	int streetNumber;                                                   //changed from unsigned to int to show error message as per assigment output
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers                                                              // Structure type Numbers declaration
{
	char cell[11];
	char home[11];
	char business[11];
};

struct Contact                                                              // Structure type Contact declaration
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;

};

//--------------------------------
// Function Prototypes
//--------------------------------


void getName(struct Name*);

void getAddress(struct Address*);

void getNumbers(struct Numbers*);

void getContact(struct Contact*);


// ----------------------------------------------------------------------------
#endif // !CONTACTS_H_                                                      //closing of the safeguard condition
