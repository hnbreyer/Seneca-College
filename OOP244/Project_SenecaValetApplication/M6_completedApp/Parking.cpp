//Parking.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Parking.h"

namespace sdds
{
    //member initializer list for menu titles
    Parking::Parking(const char* fName, int noOfSpots) : p_parkingMenu("Parking Menu, select an action:"), p_vehicleSelection("Select type of the vehicle:", 1), p_parkingSpotarray{ nullptr } 
 {
        p_filename = nullptr;
        if (fName != nullptr && fName[0] != '\0' && noOfSpots >= 10 && noOfSpots <= MAX_NUM_PSPOTS) {
            if (p_filename == nullptr) {
                p_filename = new char[strlen(fName) + 1];
                strcpy(p_filename, fName);
                p_filename[strlen(fName)] = '\0';
                p_noOfSpots = noOfSpots;
                p_numParkedVehicles = 0;
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

        for (int i = 0; i < MAX_NUM_PSPOTS; i++) {
            if (p_parkingSpotarray[i] != nullptr) {
                delete p_parkingSpotarray[i];
                p_parkingSpotarray[i] = nullptr;
            }
        }
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
        std::cout << "*****  Available spots: ";
        std::cout.width(4);
        std::cout.setf(std::ios::left);
        std::cout << p_noOfSpots - p_numParkedVehicles;
        std::cout.unsetf(std::ios::left);
        std::cout << " *****" << std::endl;
    }

    void Parking::parkVehicle()  {
        if (p_noOfSpots - p_numParkedVehicles == 0) {
            std::cout << "Parking is full" << std::endl;
        }
        else {
            switch (p_vehicleSelection.Menu::run()) {
            case 1: 
            {  Vehicle* v = new Car();
               bool error = false; 
               v->setCsv(false);
               v->read(std::cin);
        
               for (int i = 0; i <p_noOfSpots && !error; i++) {                                         //search through array to find first null space
                  if (p_parkingSpotarray[i] == nullptr) {
                      p_parkingSpotarray[i] = v;
                      p_parkingSpotarray[i]->setParkingSpot(i + 1);
                       error = true;                                                                    //flag to exit loop
                  }
               }
                p_numParkedVehicles++;

                   std::cout << '\n';
                   std::cout << "Parking Ticket" << std::endl;
                   std::cout << *v;
                   std::cout << '\n';
               }
                break;
            case 2: 
            {Vehicle* v = new Motorcycle();
            bool error_ = false;
            v->setCsv(false);
            v->read(std::cin);

            for (int i = 0; i < p_noOfSpots && !error_; i++) {
                if (p_parkingSpotarray[i] == nullptr) {
                    p_parkingSpotarray[i] = v;
                    p_parkingSpotarray[i]->setParkingSpot(i + 1);
                    error_ = true;   
                }               
            }
                        p_numParkedVehicles++;
                        std::cout << '\n';
                        std::cout << "Parking Ticket" << std::endl;
                        std::cout << *v;
                        std::cout << '\n';          
            }
                break;
            case 3: std::cout << "Parking cancelled" << std::endl;
                break;
            }
        }
    }

    void Parking::returnVehicle() {
        std::cout << "Return Vehicle" << std::endl;
        char temp_lic[8];
        std::cout << "Enter Licence Plate Number: ";
        std::cin >> temp_lic;
        charToUpper(temp_lic);

        while (strlen(temp_lic) < 1 || strlen(temp_lic) > 8) {
            std::cout << "Invalid Licence Plate, try again: ";
            std::cin >> temp_lic;
            charToUpper(temp_lic);
        }
    
            bool check = false;
            int index = 0;
            for (int i = 0; i < p_numParkedVehicles && !check; i++) {
                    switch (p_parkingSpotarray[i] != nullptr && strcmp(temp_lic, p_parkingSpotarray[i]->m_license) == 0) {
                    case true: {
                        index = i;
                        check = true;
                    }
                             break;        
                    }                   
                }
     
            if (check == true) {
            std::cout << '\n';
            std::cout << "Returning: " << std::endl;
            p_parkingSpotarray[index]->setCsv(false);
            std::cout << *p_parkingSpotarray[index];
            std::cout << '\n';
            delete p_parkingSpotarray[index];
            p_parkingSpotarray[index] = nullptr;
            p_numParkedVehicles--;
            }
            else {
                std::cout << "License plate " << temp_lic << " Not found" << std::endl;
            }
        }
    
    char* Parking::charToUpper(char* ch) const {
        int length = strlen(ch);
        for (int i = 0; i < length; i++) {
            if (ch[i] >= 'a' && ch[i] <= 'z') {
                ch[i] = ch[i] - ('a' - 'A');
            }
        }
        return ch;
    }

    void Parking::listParkedVehicles() const {
        std::cout << "*** List of parked vehicles ***" << std::endl;
        for (int i = 0; i <= p_numParkedVehicles; i++) {
            if (p_parkingSpotarray[i] != nullptr) {
                p_parkingSpotarray[i]->setCsv(false);
            std::cout << *p_parkingSpotarray[i];
            std::cout << "-------------------------------" << std::endl;
            }
        }
    }

    bool Parking::closeParking() {
        bool close = false;
        char choice[8];
        if (p_numParkedVehicles == 0) {
            std::cout << "Closing Parking" << std::endl;
            close = true;
        }
        else {
            std::cout << "This will Remove and tow all remaining vehicles from the parking!" << std::endl;
            std::cout << "Are you sure? (Y)es/(N)o: ";
            std::cin >> choice;
            std::cin.ignore();

            while (!(choice[1] == '\0')) {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                std::cin.getline(choice, 8);
            }

            if ((choice[0] == 'Y' || choice[0] == 'y') && strlen(choice) == 1) {
                std::cout << "Closing Parking" << std::endl;
                std::cout << '\n';
                for (int i = 0; i < p_noOfSpots; i++) {
                    if (p_parkingSpotarray[i] != nullptr) {
                        std::cout << "Towing request" << std::endl;
                        std::cout << "*********************" << std::endl;
                        p_parkingSpotarray[i]->setCsv(false);
                        std::cout << *p_parkingSpotarray[i];
                        if (i < 9) {
                        std::cout << '\n';
                        }
                        delete p_parkingSpotarray[i];
                        p_parkingSpotarray[i] = nullptr;
                        p_numParkedVehicles--;
                        close = true;
                    }
                }                
            }
            else if ((choice[0] == 'N' || choice[0] == 'n') && strlen(choice) == 1) {
                close = false;
                std::cout << "Aborted!" << std::endl;
            }
            }
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
        else if ((choice[0] == 'N' || choice[0] == 'n') && strlen(choice) == 1) {
            std::cin.clear();
            std::cin.ignore(2000, '\n');
            userChoice = false;
        }
        return userChoice;
    }

    bool Parking::loadDataFile() {
        std::ifstream fin;

        if (!isEmpty()) {
            fin.open(p_filename);
            }
        if (fin.fail() || isEmpty()) {
            fin.good();
        }
       
        Vehicle* v;
                char f;
                while (fin.good() && p_numParkedVehicles <= p_noOfSpots) {
                    v = nullptr;
                   f = {'\0'};
            
                    fin.get(f);
                    fin.ignore();
                if (f == 'M') {
                    v = new Motorcycle();
                }
                else if (f == 'C') {
                    v = new Car();                 
                }
                if (v) {
                    v->setCsv(true);
                    fin >> *v;                                                                 //also works: v->read(fin);
                    fin.ignore();
                  
                    if (fin) {
                        p_parkingSpotarray[v->getParkingSpot() - 1] = v;
                        p_numParkedVehicles++;
                    }
                    else {
                        delete v;
                        v = nullptr;
                        fin.fail();
                    }
                }
                }

        fin.close();
        return fin.rdstate();
    }

    void Parking::saveDataFile() const {
        std::ofstream fout;
        if (!isEmpty()) {
            fout.open(p_filename);

            if (fout.good()) {
                for (int i = 0; i <= p_noOfSpots; i++) {
                    if (p_parkingSpotarray[i] != nullptr) {
                        p_parkingSpotarray[i]->setCsv(true);
                        fout << *p_parkingSpotarray[i];
                    }
                }
            }
        }
        fout.close();
    }

    void Parking::setEmpty() {                                                                   //added function
        p_filename = nullptr;
        p_parkingMenu = nullptr;
        p_vehicleSelection = nullptr;
        for (int i = 0; i < p_noOfSpots; i++) {
            delete p_parkingSpotarray[i];
            p_parkingSpotarray[i] = nullptr;
        }
        p_numParkedVehicles = 0;
        p_noOfSpots = 0;
    }

    int Parking::run() {
        int p_run = 0;
        if (!isEmpty()) {
            parkingStatus();
            switch (p_parkingMenu.Menu::run()) {                                                    //using run function from Menu class
            case 1: parkVehicle();
                run();                                                                              //using run function from Parking class
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
                else {

                    run();
                }                
                    break;
            case 5:
                if (exitParkingApp()) {
                }
                    break;
            }
        }
        else {
            p_run = 1;
        }
        return p_run;
    }
}
