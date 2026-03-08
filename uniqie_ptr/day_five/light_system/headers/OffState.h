#ifndef OFFSTATE_H
#define OFFSTATE_H

#include "LightStates.h"


class OffState : public LightState{

public:
    void turnOn(SmartLight& light);
    void turnOff(SmartLight& light);
    void dim(SmartLight& light);
    void printState();
    

};

#endif
