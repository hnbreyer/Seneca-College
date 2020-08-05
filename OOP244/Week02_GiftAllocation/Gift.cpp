// Gift.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


#include "Gift.h"

namespace sdds
{
	void gifting(char* giftName) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> giftName;	
	}


	void gifting(double &price) {
		price = 0;
		cout << "Enter gift price: ";
		cin >> price;
		while (price < 0 || price > MAX_PRICE) {
			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}
	
	}

	void gifting(int &units) {
		units = 0;
		cout << "Enter gift units: ";
		cin >> units;
		while (units <= 0) {
			cout << "Gifts units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}
		
	}

	void display(const Gift &gifts) {
	
		cout << "Gift Details:" << endl;
		cout << "Description: " << gifts.g_description << endl;
		cout << "Price: " << gifts.g_price << endl;
		cout << "Units: " << gifts.g_units << endl;


	}
}
