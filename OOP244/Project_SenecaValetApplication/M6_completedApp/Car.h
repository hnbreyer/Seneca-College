/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
  ///I have done all the coding by myself and only copied the code that my professor provided to complete this program///
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
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;

    };
}

#endif
