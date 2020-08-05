//Saiyan.h

/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

#include <iostream>
#include <cstring>

const int MAX_LENGTH = 30;

namespace sdds
{
    class Saiyan
    {
        char m_name[MAX_LENGTH + 1];
        int m_dob;
        int m_power;
        bool m_super;

    public:
        //constructors
        Saiyan();
        Saiyan(const char* nam, int date, int pow);
        //
        bool isSuper() const;
        bool isValid() const;
        void setEmpty();
        void display() const;
        void set(const char* name, int dob, int power, bool super = false);
        bool hasLost(const Saiyan& other) const;
    };


}


#endif
