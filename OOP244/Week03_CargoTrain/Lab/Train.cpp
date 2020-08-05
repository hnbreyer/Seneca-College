//Train.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Train.h"
using namespace std;

namespace sdds
{
    void Train::setTrain(const char* nam, int i_d) {
        if (nam != nullptr && nam[0] != '\0' && i_d >= 1) {

            id = i_d;
            strcpy(name,nam);
        }
        else {

            id = 0;
            name[0] = '\0';  
        }

        cargo = nullptr;

    }

    bool Train::isEmpty() const {
        bool empty;
        if (name[0] == '\0' && id == 0) { 

            empty = true;
        }
        else {
            empty = false;
        }

        return empty;
    }

    void Train::display() const {

        cout << "***Train Summary***" << endl;

            if (isEmpty()) {
                cout << "This is an empty train." << endl;
                
            }
            else {
                cout << "Name: " << name << " ID: " << id << endl;
                
                if (cargo == nullptr) {
                    cout << "No cargo on this train." << endl;
                }
                else {
                    cout << "Cargo: " << cargo->description << " Weight: " << cargo->weight << endl;
                }
            }  
    }

    void Train::loadCargo(Cargo carg) {

        cargo = new Cargo;

        strcpy(cargo->description, carg.description);
        cargo->weight = carg.weight;
    }

    void Train::unloadCargo() {

        delete cargo;
        cargo = nullptr;
    }
}
