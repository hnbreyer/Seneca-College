//Saiyan.h

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

#include <iostream>
#include <cstring>

const int MAX_LENGTH = 30;

namespace sdds
{
    class Saiyan
    {
        char* m_name;
        int m_dob;
        int m_power;
        int m_level;
        bool m_super;

    public:
        //constructors
        Saiyan();
        Saiyan(const char* nam, int date, int pow);

        bool isSuper() const;
        bool isValid() const;
        void setEmpty();
        void display() const;
        void set(const char* name, int dob, int power, int level = 0, bool super = false);
        bool hasLost(Saiyan& other);
        void powerup();
        
        //destructor
        ~Saiyan();
    };
}

#endif
