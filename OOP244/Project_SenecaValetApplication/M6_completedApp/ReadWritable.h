/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
  ///I have done all the coding by myself and only copied the code that my professor provided to complete this program///
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
        void setCsv(bool value = false);
        //read and write
        virtual std::istream& read(std::istream& istr) = 0;
        virtual std::ostream& write(std::ostream& ostr) const = 0;
    };

    //operator overload helpers
    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& Read);
    std::istream& operator>>(std::istream& istr, ReadWritable& Write);

}

#endif
