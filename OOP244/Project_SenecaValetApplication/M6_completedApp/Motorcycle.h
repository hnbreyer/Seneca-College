/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
  ///I have done all the coding by myself and only copied the code that my professor provided to complete this program///
 **********************************************************/
 //Motorcycle.h

#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H


#include <iostream>
#include <cstring>

#include "Vehicle.h"

namespace sdds
{
    class Motorcycle : public Vehicle
    {
        bool sidecar;
    public:
        Motorcycle();
        Motorcycle(const char*, const char*);
        void setEmpty();
        Motorcycle(Motorcycle&) = delete; //copy
        Motorcycle& operator=(Motorcycle&) = delete; //copy assignment
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
    };
}

#endif
