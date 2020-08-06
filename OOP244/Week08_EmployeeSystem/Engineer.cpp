//Engineer.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Engineer.h"

namespace sdds
{
    Engineer::Engineer() {
        setEmpty();
    }

    Engineer::Engineer(double esal, int ehours, int level) : m_esalary{ 0 }, m_ewhours{ 0 }, m_level{0} {
        if (esal > 0 && ehours > 0 && level > 0) {
            m_level = level;
            m_ewhours = ehours;
            setSalary(esal);
        }
        else {
            setEmpty();
        }
    }

    void Engineer::setSalary(double esal) {
        if (m_level == MAX_LEVEL) {
            m_esalary = esal + 3000;
        }
        else {
            m_esalary = esal;
        }
    }

    bool Engineer::workHours() {
        bool minHours = false;
        if (m_ewhours == MIN_HOURS) {
            minHours = true;
        }
        return minHours;
    }

    void Engineer::bonus() {
        if (m_ewhours > MIN_HOURS && m_level == MAX_LEVEL) {
            m_esalary = (m_esalary * 0.1) + m_esalary;
        }
        else {
            m_esalary = (m_esalary * 0.05) + m_esalary;
        }
    }

    std::ostream& Engineer::display(std::ostream& os) const {
        if (m_esalary > 0 && m_ewhours > 0) {
            os << "Engineer details" << std::endl;
            os << "level: " << m_level << std::endl;
            os.setf(std::ios::fixed);
            os.precision(2);
            os << "Salary: " << m_esalary << std::endl;
            os.unsetf(std::ios::fixed);
            os << "Working hours: " << m_ewhours << std::endl;
        }
        else {
            os << "Engineer is not initiated yet" << std::endl;
        }
        return os;
    }

    void Engineer::setEmpty() {                                                       //added function
        m_esalary = 0;
        m_ewhours = 0;
        m_level = 0;
    }
}
