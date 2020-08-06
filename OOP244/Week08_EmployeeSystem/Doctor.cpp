//Doctor.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Doctor.h"

namespace sdds
{
    Doctor::Doctor() {
        setEmpty();
    }
    
    Doctor::Doctor(const char* type, double sal, int hours, bool spec) {
        if (type[0] != '\0' && sal > 0 && hours > 0) {
            strcpy(m_type, type);
            setSalary(sal);
            m_whours = hours;
            m_specialist = spec;
        }
        else {
            setEmpty();
        }        
    }

    void Doctor::setSalary(double sal) {
        if (strcmp(m_type, "General") == 0) {
            m_salary = sal;
        }
        else if (strcmp(m_type, "Specialist") == 0) {
            m_salary = sal + 2000;
        }
    }

    bool Doctor::workHours() {
        bool min_hours = false;
        if (m_whours == MIN_W_HOURS) {
            min_hours = true;
        }
        return min_hours;
    }

    void Doctor::bonus() {
        if (m_whours > MIN_W_HOURS) {
            m_salary = (m_salary * 0.1) + m_salary;
        }
        else {
            m_salary = (m_salary * 0.05) + m_salary;
        }
    }

    std::ostream& Doctor::display(std::ostream& os) const {
        if (m_salary > 0 && m_whours > 0) {
            os << "Doctor details" << std::endl;
            os << "Doctor Type: " << m_type << std::endl;
            os.setf(std::ios::fixed);
            os.precision(2);
            os << "Salary: " << m_salary << std::endl;
            os.unsetf(std::ios::fixed);
            os << "Working Hours: " << m_whours << std::endl;
        }
        else {
            os << "Doctor is not initiated yet" << std::endl;
        }
        return os;
    }

    void Doctor::setEmpty() {                                                            //added function
        m_type[0] = {};
        m_salary = 0;
        m_whours = 0;
        m_specialist = false;
    }
}
