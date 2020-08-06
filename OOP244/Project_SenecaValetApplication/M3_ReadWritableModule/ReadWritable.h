/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/
 //ReadWritable.h

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>

namespace sdds
{
    class ReadWritable
    {
        bool Csv;
    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv() const;
        void setCsv(bool value);
        //read and write
        virtual std::istream& read(std::istream& istr = std::cin) = 0;
        virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
    };

    //operator overload helpers
    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& Read);

    std::istream& operator>>(std::istream& istr, ReadWritable& Write);
}

#endif
