#ifndef ONSTATE_H
#define ONSTATE_H

#include "LightStates.h"
#include "SmartLight.h"

class OnState : public LightState{

private:

public:
    void turnOn(SmartLight& light);
    void turnOff(SmartLight& light);
    void dim(SmartLight& light);
    void printState();    

};

#endif
