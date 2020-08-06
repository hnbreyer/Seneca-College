/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/
 //Car.h

#ifndef SDDS_CAR_H
#define SDDS_CAR_H


#include <iostream>
#include <cstring>

#include "Vehicle.h"

namespace sdds
{
    class Car : public Vehicle
    {
        bool carwash;
    public:
        Car();
        Car(const char*, const char*);
        void setEmpty();
        Car(Car&) = delete; //copy
        Car& operator=(Car&) = delete; //copy assignment
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;

    };
}

#endif
