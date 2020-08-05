/***********************************************************************
// OOP244 Workshop 3: Classes & Privacy
// File TrainTester.cpp
// Version 1.0
// Date	2020/01/19
// Author Michael Huang
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Train.h"
#include "Train.h"                                                                                      // intentional
using namespace std;
using namespace sdds;

ostream& line(int len, char ch) {
	for (int i = 0; i < len; i++, cout << ch);
	return cout;
}
ostream& number(int num) {
	cout << num;
	for (int i = 0; i < 9; i++) {
		cout << " - " << num;
	}
	return cout;
}

int main() {

  sdds::Cargo c1{ "Boxes", 55.55 }; 
  sdds::Cargo c2{ "Flowers", 66.666 }; 
  sdds::Cargo c3{ "Ore", 77.7777 };

  cout << "Create a Train and attempt to set it (empty state)" << endl;
  line(64, '-') << endl; number(1) << endl;
  sdds::Train t1; 
  t1.setTrain(nullptr, 1);
  sdds::Train t2; 
  t2.setTrain("", 1);
  sdds::Train t3; 
  t3.setTrain("Birthday Train", -5);
  if (t1.isEmpty() && t2.isEmpty() && t3.isEmpty())
    cout << "Success! Each Train is in empty state" << endl;

  cout << "\nDisplay an empty Train" << endl;
  line(64, '-') << endl; number(2) << endl;
  t1.display();

  cout << "\nSet each Train to a non empty state" << endl;
  line(64, '-') << endl; number(3) << endl;
  t1.setTrain("Birthday Train", 1);
  t2.setTrain("Choo Choo Train", 2);
  t3.setTrain("Hype Train", 3);
  
  if (!t1.isEmpty() && !t2.isEmpty() && !t3.isEmpty())
    cout << "Success! Each Train is in non empty state" << endl;

  cout << "\nDisplay each non empty Train" << endl;
  line(64, '-') << endl; number(4) << endl;
  t1.display(); cout << endl; 
  t2.display(); cout << endl; 
  t3.display(); cout << endl; 

  cout << "\nLoad Cargo onto a Train and Display" << endl;
  line(64, '-') << endl; number(5) << endl;
  t1.loadCargo(c1); 
  t2.loadCargo(c2); 
  t3.loadCargo(c3);
  t1.display(); cout << endl; 
  t2.display(); cout << endl; 
  t3.display(); cout << endl; 

  cout << "\nUnload Cargo from each Train and Display" << endl;
  line(64, '-') << endl; number(6) << endl;
  t1.unloadCargo(); 
  t2.unloadCargo(); 
  t3.unloadCargo();
  t1.display(); cout << endl; 
  t2.display(); cout << endl; 
  t3.display(); cout << endl; 

  return 0;
}

/*OUTPUT

Create a Train and attempt to set it (empty state)
----------------------------------------------------------------
1 - 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1
Success! Each Train is in empty state
Display an empty Train----------------------------------------------------------------
2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2
***Train Summary***
This is an empty train.
Set each Train to a non empty state
----------------------------------------------------------------
3 - 3 - 3 - 3 - 3 - 3 - 3 - 3 - 3 - 3
Success! Each Train is in non empty state
Display each non empty Train
----------------------------------------------------------------
4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4 - 4
***Train Summary***
Name: Birthday Train ID: 1
No cargo on this train.
***Train Summary***
Name: Choo Choo Train ID: 2
No cargo on this train.
***Train Summary***
Name: Hype Train ID: 3
No cargo on this train.
Load Cargo onto a Train and Display
----------------------------------------------------------------
5 - 5 - 5 - 5 - 5 - 5 - 5 - 5 - 5 - 5
***Train Summary***
Name: Birthday Train ID: 1
Cargo: Boxes Weight: 55.55
***Train Summary***
Name: Choo Choo Train ID: 2
Cargo: Flowers Weight: 66.666
***Train Summary***
Name: Hype Train ID: 3
Cargo: Ore Weight: 77.7777
Unload Cargo from each Train and Display
----------------------------------------------------------------
6 - 6 - 6 - 6 - 6 - 6 - 6 - 6 - 6 - 6
***Train Summary***
Name: Birthday Train ID: 1
No cargo on this train.
***Train Summary***
Name: Choo Choo Train ID: 2
No cargo on this train.
***Train Summary***
Name: Hype Train ID: 3
No cargo on this train.
*/
