//Vehicle.h

/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <cstring>

const int MIN_SPEED = 100;
const int MAX_SPEED = 140;

namespace sdds
{
    class Vehicle
    {
        int m_speed;
        int m_noOfSeats;
    public:
        Vehicle();
        Vehicle(int speed, int seats);
        ~Vehicle();
        bool finetune();
        std::ostream& display(std::ostream& os) const;
        std::istream& input(std::istream& in);
    };

    //operator overload helpers
    std::ostream& operator<<(std::ostream& os, const Vehicle& v);
    std::istream& operator>>(std::istream& in, Vehicle& V);

}


#endif 
