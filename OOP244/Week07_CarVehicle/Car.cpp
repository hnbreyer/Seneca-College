//Car.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Car.h"

namespace sdds
{
    Car::Car() {
        m_carType[0] = {};
        m_regYear = 0;
    }

    Car::Car(const char* cartype, int regYear, int speed, int seats) : Vehicle(speed, seats) {
        if (cartype[0] != '\0' && regYear >= MIN_YEAR) {
            strcpy(m_carType, cartype);
            m_regYear = regYear;
        }
        else {
            m_carType[0] = {};
            m_regYear = 0;
        }
    }

    void Car::finetune() {
        if (m_regYear >= MIN_YEAR) {
            Vehicle::finetune();
            std::cout << "This car is finely tuned to default speed" << std::endl;
        }
        else {
            std::cout << "Car cannot be tuned and has to be scraped" << std::endl;
        }
    }

    std::ostream& Car::display(std::ostream& os) const {
        if (this->m_carType[0] != '\0' && this->m_regYear >= MIN_YEAR) {
            os.width(20);
            os.setf(std::ios::left);
            os << this->m_carType;
            os.unsetf(std::ios::left);
            os << this->m_regYear;
            Vehicle::display(os);
        }
        else {
            os << "Car is not initiated yet" << std::endl;
        }
        return os;
    }

    std::istream& Car::input(std::istream& in) {
        char temp_carType[MAX_CHAR + 1];
        std::cout << "Enter the car type: ";
        in.getline(temp_carType, MAX_CHAR);
        int temp_regyear;
        std::cout << "Enter the car registration year: ";
        in >> temp_regyear;

        strcpy(m_carType, temp_carType);
        m_regYear = temp_regyear;

        Vehicle::input(in);
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const Car& C) {                              //operator overload helpers
        C.display(os);
        return os;
    }

    std::istream& operator>>(std::istream& in, Car& C) {
        C.input(in);
        return in;
    }
}
