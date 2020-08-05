//Train.h

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

#include <cstring>

namespace sdds
{
    const int MAX_NAME = 30;
    const int MAX_DESC = 20;
    const double MAX_WEIGHT = 700.555;
    const double MIN_WEIGHT = 40.444;

    class Cargo
    {
        char description[MAX_DESC];
        double weight;

    public:
        Cargo();
        Cargo(const char* dsc, double wgh);
        Cargo& setDescript(const char* desc);
        Cargo& setWeight(double wei);
        char* getDescript();
        double getWeight();
        void init(const char* desc, double weit);   
    };

    class Train
    {
        char name[MAX_NAME];
        int id;
        Cargo* cargo;

    public:
        void setTrain(const char* nam, int i_d);
        bool isEmpty() const;
        void display() const;
        void loadCargo(Cargo carg);
        void unloadCargo();
        bool swapCargo(Train& train);
        bool increaseCargo(double inc);
        bool decreaseCargo(double dec);
    };
}

#endif
