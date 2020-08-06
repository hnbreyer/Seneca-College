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
        Motorcycle(Motorcycle&) = delete;                                                  //copy
        Motorcycle& operator=(Motorcycle&) = delete;                                       //copy assignment
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
    };
}

#endif
