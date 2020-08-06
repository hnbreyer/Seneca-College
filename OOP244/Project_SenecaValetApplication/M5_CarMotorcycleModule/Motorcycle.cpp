//Car.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Motorcycle.h"

namespace sdds
{
    Motorcycle::Motorcycle() {
        setEmpty();
    }

    Motorcycle::Motorcycle(const char* license, const char* makemodel) : Vehicle(license, makemodel) {
        sidecar = false;
    }

    void Motorcycle::setEmpty() {
        sidecar = false;
        Vehicle::setEmpty();
    }

    std::istream& Motorcycle::read(std::istream& istr) {
        char choice[8];
        if (this->isCsv()) {
            Vehicle::read();
            istr >> sidecar;
        }
        else {
            std::cout << std::endl;
            std::cout << "Motorcycle information entry" << std::endl;
            istr.clear();
            istr.ignore(2000, '\n');
            Vehicle::read();
            std::cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            istr.getline(choice, 8);

            while (!(choice[1] == '\0')) {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                istr.getline(choice, 8);
            }

            if ((choice[0] == 'Y' || choice[0] == 'y') && strlen(choice) == 1) {
                sidecar = true;
            }
            else if ((choice[0] == 'N' || choice[0] == 'n') && strlen(choice) == 1) {
                istr.clear();
                istr.ignore(2000, '\n');
                sidecar = false;
            }
        }
        return istr;
    }

    std::ostream& Motorcycle::write(std::ostream& ostr) const {
        if (this->isEmpty()) { 
            ostr << "Invalid Motorcycle Object" << std::endl;
        }
        else {
            if (this->isCsv()) {
                ostr << "M,";
            }
            else {
                ostr << "Vehicle type: Motorcycle" << std::endl;
            }
            Vehicle::write();
            if (this->isCsv()) {
                ostr << sidecar << std::endl;
            }
            else {
                if (sidecar == true) {
                    ostr << "With Sidecar" << std::endl;
                } 
            }
        }
        return ostr;
    }
}
