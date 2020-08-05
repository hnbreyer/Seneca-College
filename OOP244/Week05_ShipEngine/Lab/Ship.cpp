//Ship.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Ship.h"

using namespace std;

namespace sdds
{
    Ship::Ship() {
        setEmptyShip();
    }

    Ship::Ship(const char* shipT, Engine* engines, int lengthEngine) {

        setShip(shipT, engines, lengthEngine);
    }
    
    void Ship::setEmptyShip(){
        shipType[0] = '\0';
        distance = 0;
        number_engines = 0;
        for (int i = 0; i < number_engines; i++) {
            engineArr[i].setEmptyEng();
        }
    }

    void Ship::setShip(const char* type, Engine* engines, int lengthEngine) {
        if (type != nullptr && strlen(type) > 0 && strlen(type) < 7 && engines[0].get() > 0 && lengthEngine < 10) {
            strcpy(shipType, type);
            number_engines = lengthEngine;

            for (int i = 0; i < lengthEngine; i++) {
                engineArr[i] = engines[i];             
            }
        }
        else {
            setEmptyShip();
        }
    }

    bool Ship::empty() const {
        bool isEmpty = false;
       
        if (shipType == nullptr && strlen(shipType) == 0 && engineArr[0].get() > 0 && number_engines == 0) {
            isEmpty = true;
        }
        return isEmpty;
    }

    float Ship::calculatePower() const {
        float total = 0;
        for (int i = 0; i < number_engines; i++) {
            total += engineArr[i].get() * 5;
        }  
        return total;
    }


    void Ship::display() const {

        cout.setf(ios::fixed);
        cout.precision(2);

        if (!empty() && shipType[0] != '\0') {
            if (number_engines < 4) {
                
            cout << shipType << "- " << calculatePower() << endl;
            }
            else {
                cout << shipType << "-" << calculatePower() << endl;
            }
            for (int i = 0; i < number_engines; i++) {
                engineArr[i].display();          
            }
            }else {
            cout << "No available data" << endl;
        }
        }
   
    Ship& Ship::operator+=(Engine e) {

        if (shipType != nullptr && strlen(shipType) > 0 && number_engines < MAX_ENGINE) {
            engineArr[number_engines++] = e;
        }
        else {
            cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
        }
        number_engines++;

        return *this;
    }

    bool operator==(const Ship& ship, const Ship& other_ship) {
        bool samePwr = false;
        if (ship.calculatePower() == other_ship.calculatePower()) {
            samePwr = true;
        }
        return samePwr;
    }


    bool operator<(const Ship& ship, double size) {
        bool isLow = false;
        if (ship.calculatePower() < size) {
            isLow = true;
        }
        return isLow;
    }
}
