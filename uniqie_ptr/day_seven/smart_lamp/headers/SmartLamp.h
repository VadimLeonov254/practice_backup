#ifndef SMARTLAMP_H
#define SMARTLAMP_H

#include<memory>
#include "LampState.h"

class LampState;

class SmartLamp{
private:
    std::unique_ptr<LampState> state;

public:
    SmartLamp();
    std::unique_ptr<LampState> getState();
    void setState(std::unique_ptr<LampState> newstate);
    
    void performTurnOn();
    void performTurnOff();

};

#endif
