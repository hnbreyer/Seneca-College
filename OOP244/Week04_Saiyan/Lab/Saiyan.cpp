//Saiyan.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Saiyan.h"
using namespace std;

namespace sdds
{
    Saiyan::Saiyan() {
        setEmpty();
    }

    Saiyan::Saiyan(const char* nam, int date, int pow) {
        set(nam, date, pow);
        
    }

    bool Saiyan::isSuper() const {
        return m_super;
    }

    bool Saiyan::isValid() const {
        
        bool valid = false;
        if (m_name != nullptr && m_name[0] != '\0' && m_dob > 0 && m_dob < 2020 && m_power > 0) {
             valid = true;
        }   
        return valid;
    }

    void Saiyan::setEmpty() {
        m_name[0] = '\0';
        m_dob = 0;
        m_power = 0;
        m_super = false;
    }

    void Saiyan::display() const {
        if (!isValid()) {
            cout << "Invalid Saiyan!" << endl;
        }
        else {
            cout << m_name << endl;
            cout << "DOB: " << m_dob;
            cout << " Power: " << m_power << endl;
            cout << "Super Saiyan Ability: " << (isSuper() ? "S" : "Not s") << "uper Saiyan." << endl;
            cout << endl;
        }
    }

    void Saiyan::set(const char* name, int dob, int power, bool super) {
        if(!name || strlen(name) == 0 || dob > 2020 || power < 0) {
            setEmpty();          
        }
        else {
            strcpy(m_name, name);
            m_dob = dob;
            m_power = power;
            m_super = super;
        }    
            }


    bool Saiyan::hasLost(const Saiyan& other) const {
        bool result = false;

                if (!this->isValid() || !other.isValid()) {
                    result = false;
                }

                if (this->m_power < other.m_power) {
                    result = true;
                }

                return result;
            }
        }
