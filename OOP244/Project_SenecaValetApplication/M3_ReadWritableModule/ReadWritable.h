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
        virtual std::istream& read(std::istream& istr = std::cin) = 0;                                                  //read
        virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;                                          //write
    };

    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& Read);                                             //operator overload helpers
    std::istream& operator>>(std::istream& istr, ReadWritable& Write);
}

#endif
