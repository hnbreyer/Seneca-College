/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/

 //Parking.h

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <iostream>
//#include <cstring>

#include "Menu.h"

namespace sdds
{
    class Parking
    {
        char* p_filename;
        Menu p_parkingMenu;
        Menu p_vehicleSelection;

        bool isEmpty() const;
        void parkingStatus() const;
        void parkVehicle() const;
        void returnVehicle() const;
        void listParkedVehicles() const;
        bool closeParking() const;
        bool exitParkingApp() const;
        bool loadDataFile() const;
        void saveDataFile() const;
        //added functions
        void setEmpty();
      
    public:
        Parking(const char* fName);
        ~Parking();
        int run();
        Parking(const Parking&) = delete;
        Parking& operator=(const Parking&) = delete;
    };
}

#endif
