//Ship.h

#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H

#include <cstring>

#include "Engine.h"

const int MAX_ENGINE = 10;
const int MAX_SHIP = 7;

namespace sdds
{
    class Ship
    {
        Engine* engineArr;
        char* shipType;
        int number_engines;
    public:
        //constructors
        Ship();
        Ship(const char* shipT, Engine* engines, int lengthEngine);

        void setEmptyShip();
        void setShip(const char* type, Engine* engines, int lengthEngine);
        bool empty() const;
        float calculatePower() const;
        void display() const;
        Ship& operator+=(Engine e);
        friend bool operator==(const Ship& ship, const Ship& other_ship);
        ~Ship();
    };
    bool operator<(const Ship& ship, double size);
}

#endif
