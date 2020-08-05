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
        setEmptyShip();                                                                            //initialzing values to empty state
        setShip(shipT, engines, lengthEngine);
    }

    void Ship::setEmptyShip() {
        shipType = nullptr;
        number_engines = 0;
        engineArr = nullptr;
        
        for (int i = 0; i < number_engines; i++) {
            engineArr[i].setEmptyEng();
        }        
    }

    void Ship::setShip(const char* type, Engine* engines, int lengthEngine) {
        if (type != nullptr && strlen(type) < 7) {

            if (shipType == nullptr) {
                int size = 0;
                size = strlen(type);
                shipType = new char[size + 1];
                strcpy(shipType, type);
                shipType[size] = '\0';
            }

            number_engines = lengthEngine;
            if (engineArr ==  nullptr){

                if (number_engines > 0) {
                    engineArr = new Engine[number_engines];                                        //allocating memory to engine array
                    for (int i = 0; i < lengthEngine; i++) {

                        engineArr[i] = engines[i];
                    }               
                }
            }
            else {
                setEmptyShip();
            }
        }
    }

    bool Ship::empty() const {
        bool isEmpty = false;

        if (shipType == nullptr && number_engines == 0) {
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

        if (!empty() && engineArr != nullptr && shipType[0] != '\0') {
            if (number_engines < 4) {
                cout << shipType << "- " << calculatePower() << endl;
            }
            else {
                cout << shipType << "-" << calculatePower() << endl;
            }
            for (int i = 0; i < number_engines; i++) {
                engineArr[i].display();
            }
        }
        else {
            cout << "No available data" << endl;
        }
    }


    Ship& Ship::operator+=(Engine e) {

        if (number_engines != 0) {
            if (shipType[0] != '\0') {
                Engine* engineTemp;
                engineTemp = new Engine[number_engines];

                for (int i = 0; i < number_engines; i++) {
                    engineTemp[i] = engineArr[i];
                }
                delete[] engineArr;
                engineArr = nullptr;

                engineArr = new Engine[number_engines + 1];

                for (int i = 0; i < number_engines; i++) {
                    engineArr[i] = engineTemp[i];
                }
                delete[] engineTemp;
                engineTemp = nullptr;

                engineArr[number_engines] = e;
                number_engines++;             
            }
        }
        else {
            cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
        }
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

    Ship::~Ship() {
        delete[] shipType;
        shipType = nullptr;

        delete[] engineArr;
       engineArr = nullptr;
    }
}
