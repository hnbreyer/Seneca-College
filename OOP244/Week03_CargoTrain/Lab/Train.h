// Train.h

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

#include <iostream>
#include <cstring>

namespace sdds
{
    const int MAX_NAME = 30;
    const int MAX_DESC = 20;

    struct Cargo
    {
        char description[MAX_DESC];
        double weight;
    };

    class Train
    {
        char name[MAX_NAME];
        int id;
        Cargo* cargo;

    public:
        void setTrain(const char *nam, int i_d);
        bool isEmpty() const;
        void display() const;
        void loadCargo(Cargo carg);
        void unloadCargo();
    };
}

#endif
