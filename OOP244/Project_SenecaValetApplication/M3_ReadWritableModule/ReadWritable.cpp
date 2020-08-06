/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/
 //ReadWritable.cpp

#define _CRT_SECURE_NO_WARNINGS


#include "ReadWritable.h"

namespace sdds
{
    ReadWritable::ReadWritable() {
       Csv = false;
    }

    ReadWritable::~ReadWritable() {
    }

    bool ReadWritable::isCsv() const {
        return Csv;
    }

    void ReadWritable::setCsv(bool value) {
        Csv = value;
    }

    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& Write) {
        Write.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, ReadWritable& Write) {
        Write.read(istr);
        return istr;
    }

}
