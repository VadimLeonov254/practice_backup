#ifndef ONSTATE_H
#define ONSTATE_H

#include "LampState.h"
#include "SmartLamp.h"

class OnState{
public:
    void turnOn(SmartLamp& lamp);
    void turnOff(SmartLamp& lamp);
    void printStatus();
};

#endif 
