//Engine.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Engine.h"
#include "Ship.h"

using namespace std;

namespace sdds
{
    Engine::Engine() {
        setEmptyEng();
    }

    Engine::Engine(const char* t, double s) {
        if (strlen(t) < 1 && s < 0) {
            setEmptyEng();
        }
        else {
            setEng(t, s);
        }
    }

    void Engine::setEmptyEng() {
        engineType[0] = '\0';
        size = 0;
    }

    void Engine::setEng(const char* enT, double sz) {
        if (enT != nullptr && enT[0] != '\0' && strlen(enT) < 7 && sz > 0) {

            strcpy(engineType, enT);
            size = sz;
        }
        else {
            setEmptyEng();
        }
    }

    double Engine::get() const {
        return size;
    }

    void Engine::display() const {
        if (engineType != nullptr && engineType[0] != '\0' && size > 0) {
            cout << size << " liters - " << engineType << endl;
        }
    }
}
