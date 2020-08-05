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
        setEmpty();
        set(nam, date, pow);
    }

    bool Saiyan::isSuper() const {
        return m_super;
    }

    bool Saiyan::isValid() const {
        bool valid = false;
        
        if (m_name != nullptr && m_name[0] != '\0' && m_dob < 2020 && m_power > 0) {
            valid = true;
        }
        return valid;
    }

    void Saiyan::setEmpty() {
        m_name = nullptr;
        m_dob = 0;
        m_power = 0;
        m_level = 0;
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
            if (isSuper()) {
                cout << "Super Saiyan level is: " << m_level << endl;
            }
            if (m_level <= 0) {                                                                   //avoiding double spacing in output

                
                cout << endl;
            }
        }
    }

    void Saiyan::set(const char* name, int dob, int power, int level, bool super) {

        if (name != nullptr && name[0] != '\0' && dob < 2020 && power > 0) {
            if (m_name == nullptr) {
                int size = 0;
                size = strlen(name);
                m_name = new char[size + 1];
                strcpy(m_name, name);
                m_name[size] = '\0';
            }
            m_dob = dob;
            m_power = power;
            m_super = super;
            if (isSuper()) {
            m_level = level;
            }
        }
        else {
            setEmpty();
        }
    }

    bool Saiyan::hasLost(Saiyan& other) {
        bool result = false;
        this->powerup();
        other.powerup();

        if (!this->isValid() || !other.isValid()) {
            result = false;
        }

        if (this->m_power < other.m_power) {           
            result = true;
        }          
        return result;
    }

    void Saiyan::powerup() {
            if (this->isSuper()) {
            this->m_power = this->m_power * (this->m_level + 1);
            }      
    }

    Saiyan::~Saiyan() {
        delete[] m_name;
        m_name = nullptr;
    }
}
