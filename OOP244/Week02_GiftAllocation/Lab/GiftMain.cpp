//***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading 
// File GiftMain.cpp
// Version 1.0
// Date	2020/01/05
// Author Michael Huang
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
//***********************************************************************/

#include <iostream>
#include "Gift.h"
#include "Gift.h"                                                                                 // Intentional
using namespace std;
using namespace sdds;

int main() {
  int numberOfGifts = 0;                                                                          // Initial number of Gifts
 
  Gift *pGift = nullptr;
  

  cout << "Enter number of Gifts to allocate: ";
  cin >> numberOfGifts;

  if (numberOfGifts < 1) return 1;

  pGift = new Gift[numberOfGifts]; 


  for (int i = 0; i < numberOfGifts; ++i) {
    cout << "Gift #" << i + 1 << ": " << endl;
   

    gifting(pGift[i].g_description);                                                             //this function allows the user to input gift's description    

    cin.ignore(2000,'\n');                                                                       // clear input buffer

    gifting(pGift[i].g_price);                                                                   //this function allows the user to input gift's price
    
    cin.ignore(2000,'\n'); 


    gifting(pGift[i].g_units);                                                                  //this function allows the user to input the number of units for each gift

    cin.ignore(2000, '\n');
    cout << endl;
  }

  for (int i = 0; i < numberOfGifts; ++i) {
      cout << "Gift #" << i + 1 << ": " << endl;
      display(pGift[i]);                                                                        //this function shows description, price and units for each gift
      cout << endl;
  }
  

  delete[] pGift;
  pGift = nullptr;

  return 0;
}

/* OUTPUT
Enter number of Gifts to allocate: 4
Gift #1:
Enter gift description: Roses
Enter gift price: 5.99
Enter gift units: 5
Gift #2:
Enter gift description: Gift-card
Enter gift price: -99.99
Gift price must be between 0 and 999.99
Enter gift price: 1000
Gift price must be between 0 and 999.99
Enter gift price: 50Enter gift units: 1
Gift #3:
Enter gift description: Hugs
Enter gift price: 0
Enter gift units: -5
Gift units must be at least 1
Enter gift units: 0
Gift units must be at least 1
Enter gift units: 25
Gift #4:
Enter gift description: cardcardcardcard
Enter gift price: 2
Enter gift units: 3
Gift #1:
Gift Details:
Description: Roses
Price: 5.99
Units: 5
Gift #2:
Gift Details:
Description: Gift-card
Price: 50
Units: 1
Gift #3:
Gift Details:
Description: Hugs
Price: 0
Units: 25
Gift #4:
Gift Details:
Description: cardcardcardcar
Price: 2
Units: 3
*/
