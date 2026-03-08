#ifndef DIMSTATE_H
#define DIMSTATE_H

#include "LightStates.h"

class DimState : public LightState{

public:
    void turnOn(SmartLight& light);
    void turnOff(SmartLight& light);
    void dim(SmartLight& light);
    void printState();    

};

#endif
