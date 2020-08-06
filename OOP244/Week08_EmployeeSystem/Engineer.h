//Engineer.h

/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/
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
        //added functions
        void setEmpty();
       // virtual ~Engineer();
    };
}


#endif 
