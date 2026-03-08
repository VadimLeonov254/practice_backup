#ifndef OFFSTATE_H
#define OFFSTATE_H

#include "OffState.h"

class OffState{
public:
    void turnOn(SmartLamp& lamp);
    void turnOff(SmartLamp& lamp);
    void printState();
};

#endif
