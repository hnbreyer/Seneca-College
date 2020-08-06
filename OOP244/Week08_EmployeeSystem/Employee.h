//Employee.h

/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/
#ifndef SDDS_EMPLOYEE_H__
#define SDDS_EMPLOYEE_H__

#include <iostream>

namespace sdds
{
    class Employee
    {
    public:
        virtual void setSalary(double) = 0;
        virtual void bonus() = 0;
        virtual bool workHours() = 0;
        virtual std::ostream& display(std::ostream& os) const = 0;
        virtual ~Employee() {

        }

    };
}


#endif 
