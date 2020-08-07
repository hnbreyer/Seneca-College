//Parking.h

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <iostream>
#include <string>
#include <fstream> 

#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

const int MAX_NUM_PSPOTS = 100;

namespace sdds
{
    class Parking
    {
        char* p_filename;
        Menu p_parkingMenu;
        Menu p_vehicleSelection;
        int p_noOfSpots;
        Vehicle* p_parkingSpotarray[MAX_NUM_PSPOTS];
        int p_numParkedVehicles;
  
        bool isEmpty() const;
        void parkingStatus() const;
        void parkVehicle();
        void returnVehicle();
        void listParkedVehicles() const;
        bool closeParking();
        bool exitParkingApp() const;
        bool loadDataFile();
        void saveDataFile() const;
        void setEmpty();                                                                 //added function
        
    public:
        Parking(const char* fName, int noOfSpots);
        ~Parking();
        int run();
        Parking(const Parking&) = delete;
        Parking& operator=(const Parking&) = delete;
        char* charToUpper(char* ch) const;
    };  
}

#endif
