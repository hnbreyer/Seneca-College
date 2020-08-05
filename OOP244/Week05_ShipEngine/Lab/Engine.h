//Engine.h

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

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
