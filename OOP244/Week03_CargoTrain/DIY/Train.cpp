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
            strcpy(name, nam);
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
                cout.setf(ios::fixed);
                cout.precision(2); //2 decimal places of precision
                cout << "Cargo: " << cargo->getDescript() << " Weight: " << cargo->getWeight() << endl;
            }
        }
    }

    void Train::loadCargo(Cargo carg) {

        cargo = new Cargo;

        cargo->setDescript(carg.getDescript());
        cargo->setWeight(carg.getWeight());
    }

    void Train::unloadCargo() {

        delete cargo;
        cargo = nullptr;
    }

    bool Train::swapCargo(Train& train) {
        bool success = false;
        Cargo* tempCargo;
       
        if (train.cargo != nullptr) {
            tempCargo= train.cargo;
            train.cargo = cargo;
            cargo = tempCargo;

            success = true;
        }
        return success;
    }

    Cargo::Cargo() {                                                                    //constructor
        description[0] = '\0';
        weight = 0.0; 
    } 
    
    Cargo::Cargo(const char* dsc, double wgh) {                                         //constructor
        setDescript(dsc);
        setWeight(wgh);
    }

    double Cargo::getWeight() {
        return weight; 
    }

    Cargo& Cargo::setWeight(double wei) {
  
        if(getWeight() < MIN_WEIGHT){
            weight = MIN_WEIGHT;

        }
        else if(getWeight() > MAX_WEIGHT){
            weight = MAX_WEIGHT;
        }
        else {
            weight = wei;
        }
        return *this;
    }

    char* Cargo::getDescript() {
        return description;
    }

    Cargo& Cargo::setDescript(const char* desc) {

        if (desc[0] != '\0') {
            strcpy(description, desc);    
        }    
            return *this;
    }

    void Cargo::init(const char* desc, double weit) {
        int descLen = strlen(desc);
        if (descLen <= MAX_DESC) {
            setDescript(desc);
        }

        if ((weit <= MIN_WEIGHT) && (weit >= MIN_WEIGHT)) {
            setWeight(weit);      
        }
        else {
            weit = MIN_WEIGHT;
        }
    }
  
    bool Train::increaseCargo(double inc) {
        bool increase = false;
        double incCargo;

        if (cargo != nullptr) {
            incCargo = cargo->getWeight() + inc;
            if ((incCargo > MAX_WEIGHT) && (cargo->getWeight() != MAX_WEIGHT)) {
                cargo->setWeight(MAX_WEIGHT);
                increase = true;
            }
            else if (incCargo < MAX_WEIGHT) {
                cargo->setWeight(incCargo);
                increase = true;
            }
            else if (cargo->getWeight() == MAX_WEIGHT) {
                increase = false;
            }
        }
        else {
            increase = false;
        }
        return increase;
    }

    bool Train::decreaseCargo(double dec) {
        bool decrease = false;
        double decCargo;

        if (cargo != nullptr) {
            decCargo = cargo->getWeight() - dec;
            if (decCargo < MIN_WEIGHT && (cargo->getWeight() != MIN_WEIGHT)) {
                cargo->setWeight(MIN_WEIGHT);
                decrease = true;
            }
            else if (decCargo > MIN_WEIGHT) {
                cargo->setWeight(decCargo);
                decrease = true;
            }
            else if (cargo->getWeight() == MIN_WEIGHT) {
                decrease = false;
            }
        }
        else {
            decrease = false;
        }

        return decrease;
    }
    }
