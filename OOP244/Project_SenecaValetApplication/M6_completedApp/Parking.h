/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
  ///I have done all the coding by myself and only copied the code that my professor provided to complete this program///
 **********************************************************/

 //Parking.h

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <iostream>
//#include <cstring>
#include <string>
#include <fstream> 

#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

const int MAX_NUM_PSPOTS = 100;

namespace sdds
{
    //class VehicleFile;
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
        //added functions
        void setEmpty();
        

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
