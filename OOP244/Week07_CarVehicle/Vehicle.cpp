//Vehicle.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Vehicle.h"

namespace sdds
{
    Vehicle::Vehicle() {
        m_speed = 0;
        m_noOfSeats = 0;
    }

    Vehicle::Vehicle(int speed, int seats) {
        m_speed = 0;
        m_noOfSeats = 0;
        if (speed >= MIN_SPEED && seats > 0) {
            m_speed = speed;
            m_noOfSeats = seats;
        }
        else {
            m_speed = 0;
            m_noOfSeats = 0;
        }     
    }

    Vehicle::~Vehicle() {
    }

    bool Vehicle::finetune() {
        bool tune = false;
        if (m_speed > MAX_SPEED) {
            m_speed = MIN_SPEED;
            tune = true;
        }
        else {
            std::cout << "The car cannot be tuned" << std::endl;
            tune = false;
        }
        return tune;
    }

    std::ostream& Vehicle::display(std::ostream& os) const {
        if (m_speed == 0 && m_noOfSeats == 0) {
            os << "This Car is not initiated" << std::endl;
        }
        if (m_speed >= MIN_SPEED && m_noOfSeats > 0) {
            os << "|" << m_speed << "|" << m_noOfSeats << std::endl;
        }    
            if (m_speed > MAX_SPEED) {
            os << "Car has to be fine tuned for speed limit" << std::endl;
        }
        return os;
    }

    std::istream& Vehicle::input(std::istream& in) {
        int temp_speed;
        std::cout << "Enter the Vehicle's speed: ";
        in >> temp_speed;
        int temp_seats;
        std::cout << "Enter no of seats: ";
        in >> temp_seats;

        *this = Vehicle(temp_speed, temp_seats);

        return in;
    }

std::ostream& operator<<(std::ostream& os, const Vehicle& v) {                          //operator overload helpers
    v.display(os);
    return os;
}

std::istream& operator>>(std::istream& in, Vehicle& V) {
V.input(in);
return in;
}

};
