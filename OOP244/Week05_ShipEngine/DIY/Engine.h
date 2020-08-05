#pragma once

//Engine.h

/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

 //#include <iostream>
#include <cstring>

const int MAX_LENGTH = 30;

namespace sdds
{
    class Engine
    {
        double size;
        char engineType[MAX_LENGTH + 1];

    public:
        //constructors
        Engine();
        Engine(const char* t, double s);
        void setEmptyEng();
        void setEng(const char* enT, double sz);
        double get() const;
        void display() const;

    };





}


#endif
