//Car.h

/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <cstring>

#include"Vehicle.h"

const int MIN_YEAR = 2000;
const int MAX_CHAR = 20;

namespace sdds
{
    class Car : public Vehicle
    {
        char m_carType[MAX_CHAR + 1];
        int m_regYear;
    public:
        Car();
        Car(const char* cartype, int regYear, int speed, int seats);
        void finetune();
        std::ostream& display(std::ostream& os) const;
        std::istream& input(std::istream& in);



    };
    std::ostream& operator<<(std::ostream& os, const Car& C);
   
    std::istream& operator>>(std::istream& in, Car& C);
}


#endif
