#ifndef LAMPSTATE_H
#define LAMPSTATE_H

#include "SmartLamp.h"

class SmartLamp;

class LampState{

public:
    
    void turnOn(SmartLamp& lamp);
    void turnOff(SmartLamp& lamp);
    void printStatus();
};

#endif
