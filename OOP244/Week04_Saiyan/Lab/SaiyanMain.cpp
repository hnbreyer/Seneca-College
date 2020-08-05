// OOP244 Workshop 4: Constructors 
// File: SaiyanMain.cpp
// Version: 1.0
// Date: 1/24/2020
// Author: Mohammad Shamas
/////////////////////////////////////////////

#include <iostream>
#include "Saiyan.h"
#include "Saiyan.h"  
#include "Utils.h"
using namespace std;
using namespace sdds;

int main() {
    // constructors
    Saiyan s1("Goku", 1990, 23000);
    Saiyan s2, s3;
    Saiyan badData[] = {
      Saiyan("Nappa", 2025, 1),
      Saiyan("Nappa", 2018, -1),
      Saiyan(nullptr, 2015, 1),
      Saiyan("", 2018, 5),
    };

    cout << "Testing Saiyan objects" << endl << endl;

    s3.display();                                                                          // testing two invalid Saiyans
    s2.display();

    cout << endl;

    s1.display();                                                                         // testing Valid Saiyan

    s2.set("Vegeta", 1989, 22000);                                                        // setting the second one to Vegeta

    s2.display();

    s1.set("Goku", 1990, 23000, true);                                                     // setting the Saiyan Goku to SuperSaiyan

    s1.display();

    cout << "S1 attacking S2, Battle " << (!(s1.hasLost(s2)) ? "Won" : "Lost")<< endl;      // Checking hasLost;

    cout << "S2 attacking S1, Battle " << (!(s2.hasLost(s1)) ? "Won" : "Lost") << endl;
 
    cout << endl << "None should be Valid:" << endl;                                        // making sure all the conditions are met for an inValid Saiyan
    for (int i = 0; i < 4; i++) {
        cout << "index: " << i << " - " << (badData[i].isValid() ? "V" : "Not v") << "alid." << endl;
    }
    return 0;
}

/* OUTPUT
Testing Saiyan objects

Invalid Saiyan!
Invalid Saiyan!

Goku
DOB: 1990 Power: 23000
Super Saiyan Ability: Not super Saiyan.

Vegeta
DOB: 1989 Power: 22000
Super Saiyan Ability: Not super Saiyan.

Goku
DOB: 1990 Power: 23000
Super Saiyan Ability: Super Saiyan.

S1 attacking S2, Battle Won
S2 attacking S1, Battle Lost

None should be Valid:
index: 0 - Not valid.
index: 1 - Not valid.
index: 2 - Not valid.
index: 3 - Not valid.
*/
