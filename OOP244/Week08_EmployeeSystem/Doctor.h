//Doctor.h

#ifndef SDDS_DOCTOR_H__
#define SDDS_DOCTOR_H__

#include <cstring>
#include "Employee.h"

const int MIN_W_HOURS = 6;
const int MAX_CHAR = 20;

namespace sdds
{
    class Doctor :public Employee
    {
        char m_type[MAX_CHAR + 1];
        double m_salary;
        int m_whours;
        bool m_specialist;
    public:
        Doctor();
        Doctor(const char* type, double sal, int hours, bool spec = false);
        void setSalary(double sal);
        bool workHours();
        void bonus();
        std::ostream& display(std::ostream& os) const;
        void setEmpty();                                                                //added function
    };
}

#endif 
