//Car.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Car.h"

namespace sdds
{
    Car::Car() {
        setEmpty();
    }

    Car::Car(const char* license, const char* makemodel) : Vehicle(license, makemodel) {
        carwash = false;
    }

    void Car::setEmpty() {
        carwash = false;
        Vehicle::setEmpty();
    }

    std::istream& Car::read(std::istream& istr) {
        char choice[2];
        if (this->isCsv()) {
            Vehicle::read(istr);
            istr >> carwash;
        }
        else {
            std::cout << std::endl;
            std::cout << "Car information entry" << std::endl;
            Vehicle::read(istr);
            std::cout << "Carwash while parked? (Y)es/(N)o: ";
            istr >> choice;
            istr.ignore();

            while (!(choice[1] == '\0')) {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                istr.getline(choice, 2);
            }

            if ((choice[0] == 'Y' || choice[0] == 'y') && strlen(choice) == 1) {
                carwash = true;
            }
            else if ((choice[0] == 'N' || choice[0] == 'n') && strlen(choice) == 1) {
                carwash = false;
            }           
        }
        
        return istr;
    }

    std::ostream& Car::write(std::ostream& ostr) const {
        if (this->isEmpty()) {
            ostr << "Invalid Car Object" << std::endl;
        }
        else {
            if (this->isCsv()) {
                ostr << "C,";
            }
            else {
                ostr << "Vehicle type: Car" << std::endl;
            }
            Vehicle::write(ostr);
            if (this->isCsv()) {
                ostr << carwash << std::endl;
            }
            else {
                if (carwash == true) {
                    ostr << "With Carwash" << std::endl;
                }
                else {
                    ostr << "Without Carwash" << std::endl;
                }
            }
        }
        return ostr;
    }
}
