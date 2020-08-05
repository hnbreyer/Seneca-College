// Gift.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Gift.h"

namespace sdds
{
	void gifting(char* giftName) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> giftName;
	}


	void gifting(double& price) {
		price = 0;
		cout << "Enter gift price: ";
		cin >> price;
		while (price < 0 || price > MAX_PRICE) {
			cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}
	}

	void gifting(int& units) {
		units = 0;
		cout << "Enter gift units: ";
		cin >> units;
		while (units <= 0) {
			cout << "Gifts units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}
	}

	void gifting(Gift& gift) {                                                                        //new gifting function
		cout << "Preparing a gift..." << endl;
		gifting(gift.g_description);
		gifting(gift.g_price);
		gifting(gift.g_units);
		wrap(gift);
	}

	void display(const Gift& gifts) {

		if (gifts.wrap_layers > 0) {

			cout << "Gift Details:" << endl;
			cout << "Description: " << gifts.g_description << endl;
			cout << "Price: " << gifts.g_price << endl;
			cout << "Units: " << gifts.g_units << endl;
			cout << "Wrap layers: " << gifts.wrap_layers << endl;
			for (int i = 0; i < gifts.wrap_layers; i++) {
				cout << "Wrap #" << i + 1 << ": " << gifts.wrap[i].pattern << endl;
			}	
		}
		else {

			cout << "Gift Details:" << endl;
			cout << "Description: " << gifts.g_description << endl;
			cout << "Price: " << gifts.g_price << endl;
			cout << "Units: " << gifts.g_units << endl;
			cout << "Unwrapped" << endl;
		}	
	}

	bool wrap(Gift& gifts) {
		bool success = false;

		if (gifts.wrap_layers == 0) {
			cout << "Wrapping gifts..." << endl;
			do {
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> gifts.wrap_layers;
				if (gifts.wrap_layers < 1) {
					cout << "Layers at  minimum must be 1, try again." << endl;
				}
			} while (gifts.wrap_layers < 1);

			gifts.wrap = new Wrapping[gifts.wrap_layers];
			gifts.wrap->pattern = new char[MAX_PAT];
			
			for (int i = 0; i < gifts.wrap_layers; i++) {
				
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> gifts.wrap->pattern;
				
				success = true;
			}
		}
		else {
			cout << "Gift is already wrapped!" << endl;	
		}

		return success;
	}

	
	bool unwrap(Gift& gifts) {
		bool success = true;

		if (gifts.wrap_layers > 0) {
			cout << "Gift being unwrapped." << endl;
		
			delete[] gifts.wrap;
			gifts.wrap = nullptr;
			gifts.wrap_layers = 0;
		}
		else {
			cout << "Gift isn't wrapped! Can't unwrap." << endl;
			success = false;
		}
		return success;
	}
	
}
