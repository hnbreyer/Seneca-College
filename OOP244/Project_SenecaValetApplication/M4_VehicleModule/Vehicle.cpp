//Vehicle.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Vehicle.h"

namespace sdds
{
    Vehicle::Vehicle() : m_license { 0 }, m_makeModel{ nullptr }, m_parkingSpot{ 0 } {  
    }

    Vehicle::Vehicle(const char* license, const char* makemodel) : m_license{ 0 }, m_makeModel{nullptr}, m_parkingSpot{ 0 } {
   
        if (license != nullptr && makemodel != nullptr && license[0] != '\0'  && makemodel[0] != '\0' && strlen(makemodel) > 1 && strlen(license) < 9) {
            strcpy(m_license, license);
            setMakeModel(makemodel);
        }
        else {
            setEmpty();
        }
    }

    Vehicle::~Vehicle() {
        delete[] m_makeModel;
        m_makeModel = nullptr;
    }

    void Vehicle::setEmpty() {
        if (m_makeModel != nullptr) {
            delete[] m_makeModel;
        }
        m_makeModel = nullptr;
      
        m_license[0] = '\0';
        m_parkingSpot = 0;
    }

    bool Vehicle::isEmpty() const {
        bool empty = true;
        if (m_license[0] != '\0' && m_makeModel != nullptr && m_makeModel[0] != '\0') {
            empty = false;
        }
        return empty;
    }

    char Vehicle::getLicensePlate() const {
        return *m_license;
    }

    char Vehicle::getMakeModel() const {
        return *m_makeModel;
    }

 
    void Vehicle::setMakeModel(const char* mkmodel) {
        if (mkmodel != nullptr && mkmodel[0] != '\0' && strlen(mkmodel) > 1) {
            if (m_makeModel != nullptr) {
            delete[] m_makeModel;
            m_makeModel = nullptr;
            }
            m_makeModel = new char[strlen(mkmodel) + 1];
            m_makeModel[strlen(mkmodel)] = '\0';
        }
        else {
            setEmpty();       
        }
    }

    int Vehicle::getParkingSpot() const {
        return m_parkingSpot;
    }

    void Vehicle::setParkingSpot(const int pSpot) {
        if (pSpot > 0) {
            m_parkingSpot = pSpot;
        }
        else {
            setEmpty();
        }
    }

    bool Vehicle::operator==(const char* otherLicense) const {                                              //compares 2 license plates
        bool identical = false;
        if (strcasecmp(this->m_license, otherLicense) == 0) {                                               //_stricmp in VS; requires <cctype> 
            identical = true;
        }
        return identical;
    }

    bool Vehicle::operator==(const Vehicle& other) const {                                                  //compares 2 vehicles
        bool identic = false;
        if (strcasecmp(this->m_license, other.m_license) == 0) {                                            //_stricmp in VS; requires <cctype> 
            identic = true;
        }
        return identic;
    }


    std::istream& Vehicle::read(std::istream& istr) {
        if (this->isCsv()) {
            if (istr) {
            istr >> m_parkingSpot;
            istr.ignore(1, ',');
            istr.getline(m_license, 8, ',');
            charToUpper(m_license);
            //istr.ignore(2, ',');  //??

            char temp_makemodel[61] = { '\0' };
            istr.getline(temp_makemodel, 61, ',');
            setMakeModel(temp_makemodel);
            int size = strlen(temp_makemodel);
            for (int i = 0; i < size; i++) {
                m_makeModel[i] = temp_makemodel[i];
            }
            m_makeModel[size] = '\0';
            }
            else if(istr.fail()) {
                setEmpty();
            }            
        }
        else {
            if (istr) {
            for (int i = 0; i < MAX_LICENSE; i++) {
                  m_license[i] = '\0';
            }
            std::cout << "Enter Licence Plate Number: ";
            do {
                istr.getline(m_license, 10);
                if (strlen(m_license) > 8) {
                    std::cout << "Invalid Licence Plate, try again: ";
                }
                
            } while (strlen(m_license) > 8);

            charToUpper(m_license);
  
            std::cout << "Enter Make and Model: ";
            char temp_makemodel[61] = { '\0' };
            istr.getline(temp_makemodel, 60, '\n');
            while (temp_makemodel[1] == '\0' || temp_makemodel[60] != '\0') {
                std::cout << "Invalid Make and model, try again: ";
                istr >> temp_makemodel;
            }
            setMakeModel(temp_makemodel);
            int size = strlen(temp_makemodel);
            for (int i = 0; i < size; i++) {
                m_makeModel[i] = temp_makemodel[i];
            }
            m_makeModel[size] = '\0';

            m_parkingSpot = 0;
            } else if (istr.fail()) {
                setEmpty();
            }
        }
        return istr;
    }

    char* Vehicle::charToUpper(char* ch) const{
        int length = strlen(ch);
        for (int i = 0; i < length ; i++) {

            if (ch[i] >= 'a' && ch[i] <= 'z') {
                ch[i] = ch[i] - ('a' - 'A');
        }
        }
        return ch;
    }

    std::ostream& Vehicle::write(std::ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Invalid Vehicle Object" << std::endl;
        }
        else {
            if (this->isCsv()) {
                ostr << m_parkingSpot << "," << m_license << "," << m_makeModel << ",";
            }
            else {
                ostr << "Parking Spot Number: ";
                if (m_parkingSpot == 0) {
                    ostr << "N/A" << std::endl;
                }
                else {
                    ostr << m_parkingSpot << std::endl;
                }
                ostr << "Licence Plate: " << m_license << std::endl;
                ostr << "Make and Model: " << m_makeModel << std::endl;
            }
        }
        return ostr;
    }
}
