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
