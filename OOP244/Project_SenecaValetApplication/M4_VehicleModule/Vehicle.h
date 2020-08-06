/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/
 //Vehicle.h

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <cstring>
#include <strings.h>
//#include <cctype>

#include "ReadWritable.h"

const int MAX_LICENSE = 8;

namespace sdds
{
    class Vehicle : public ReadWritable
    {
        char m_license[MAX_LICENSE + 1];
        char* m_makeModel;
        int m_parkingSpot;
    protected:
        void setEmpty();
        bool isEmpty() const;
        char getLicensePlate() const;
        char getMakeModel() const; 
        void setMakeModel(const char* mkmodel);
    public:
        Vehicle();
        Vehicle(const char* license, const char* makemodel);
        ~Vehicle();
        int getParkingSpot() const; 
        void setParkingSpot(const int pSpot);
        bool operator==(const char* otherLicense) const; //compares 2 license plates
        bool operator==(const Vehicle& other) const; //compares 2 vehicles
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        char* charToUpper(char* ch) const;
    };
}


#endif
