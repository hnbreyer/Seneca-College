/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/
 //Parking.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Parking.h"

namespace sdds
{
    //member initializer list for menu titles
    Parking::Parking(const char* fName) :p_parkingMenu("Parking Menu, select an action:"), p_vehicleSelection("Select type of the vehicle:", 1) {
        p_filename = nullptr;
        if (fName != nullptr && fName[0] != '\0') {
            if (p_filename == nullptr) {
                p_filename = new char[strlen(fName) + 1];
                strcpy(p_filename, fName);
                p_filename[strlen(fName)] = '\0';
            }
        }
        else {
            setEmpty();
        }

        if (this->loadDataFile()) {
            p_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
            p_vehicleSelection << "Car" << "Motorcycle" << "Cancel";
        }
        else {
            std::cout << "Error in data file" << std::endl;
            setEmpty();
        }
    }

    Parking::~Parking() {
        saveDataFile();
        delete[] p_filename;
        p_filename = nullptr;
    }

    bool Parking::isEmpty() const {
        bool empty = false;
        if (p_filename == nullptr || p_filename[0] == '\0') {
            empty = true;
        }
        return empty;
    }

    void Parking::parkingStatus() const {
        std::cout << "****** Seneca Valet Parking ******" << std::endl;
    }

    void Parking::parkVehicle() const {

        switch (p_vehicleSelection.Menu::run()) {
        case 1: std::cout << "Parking Car" << std::endl;
            break;
        case 2: std::cout << "Parking Motorcycle" << std::endl;
            break;
        case 3: std::cout << "Cancelled parking" << std::endl;
            break;
        }
    }

    void Parking::returnVehicle() const {
        std::cout << "Returning Vehicle" << std::endl;
    }

    void Parking::listParkedVehicles() const {
        std::cout << "Listing Parked Vehicles" << std::endl;
    }

    bool Parking::closeParking() const {
        bool close = true;
        std::cout << "Closing Parking" << std::endl;
        return close;
    }

    bool Parking::exitParkingApp() const {
        bool userChoice = false;
        char choice[8];
        std::cout << "This will terminate the program!" << std::endl;
        std::cout << "Are you sure? (Y)es/(N)o: ";
        std::cin.getline(choice, 8);
        

        while (!(choice[1] == '\0')) {
            std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            std::cin.getline(choice, 8);
        }

        if ((choice[0] == 'Y' || choice[0] == 'y') && strlen(choice) == 1) {
            userChoice = true;
            std::cout << "Exiting program!" << std::endl;
        }
        else if((choice[0] == 'N' || choice[0] == 'n') && strlen(choice) == 1){
            std::cin.clear();
            std::cin.ignore(2000, '\n');
            userChoice = false;
        }
        return userChoice;
    }

    bool Parking::loadDataFile() const {
        bool valid = false;
        if (!isEmpty()) {
            std::cout << "loading data from " << p_filename << std::endl;
            valid = true;
        }
        return valid;
    }

    void Parking::saveDataFile() const {
        if (!isEmpty()) {
            std::cout << "Saving data into " << p_filename << std::endl;
        }
    }

    //added function
    void Parking::setEmpty() {
        p_filename = nullptr;
        p_parkingMenu = nullptr;
        p_vehicleSelection = nullptr;
    }

    int Parking::run() {
        int p_run = 0;
        if (!isEmpty()) {
            parkingStatus();
            //using run function from Menu class
            switch (p_parkingMenu.Menu::run()) {
            case 1: parkVehicle();
            //using run function from Parking class
                run();
                break;
            case 2: returnVehicle();
                run();
                break;
            case 3: listParkedVehicles();
                run();
                break;
            case 4: 
                if (closeParking()) {
                    break;
                }
            case 5: 
                if (exitParkingApp()) {
                    break;
                }
            }
        }
        else {
            p_run = 1;
        }
            return p_run;
    }

}
