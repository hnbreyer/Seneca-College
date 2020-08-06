//Engineer.h

#ifndef SDDS_ENGINEER_H__
#define SDDS_ENGINEER_H__

#include "Employee.h"

const int MIN_HOURS = 5;
const int MAX_LEVEL = 4;

namespace sdds
{
    class Engineer : public Employee
    {
        double m_esalary;
        int m_ewhours;
        int m_level;
    public:
        Engineer();
        Engineer(double esal, int ehours, int level);
        void setSalary(double esal);
        bool workHours();
        void bonus();
        std::ostream& display(std::ostream& os) const;
        void setEmpty();                                                           //added function
    };
}


#endif 
