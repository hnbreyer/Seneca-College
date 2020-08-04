struct Name {                                                        // Structure type Name declaration (Milestone 1)
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};
                                                           
struct Address                                                       // Structure type Address declaration
{
	unsigned int streetNumber;                                   //only accepts positive values
	char street[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers                                                      // Structure type Numbers declaration
{
	char cell[11];
	char home[11];
	char business[11];
};

struct Contact                                                      // Structure type Contact declaration
{
	struct Name name;
	struct Address address;
	struct Numbers numbers;
	
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
void getName(struct Name *);


// Get and store from standard input the values for Address
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers *);
