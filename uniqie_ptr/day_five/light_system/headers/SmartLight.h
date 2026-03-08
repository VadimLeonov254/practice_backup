#ifndef SMARTLIGHTER_H
#define SMARTLIGHTER_H
#include<memory>
#include "LightStates.h"
class SmartLight{

private:
    std::unique_ptr<LightState> state;
    int dimLevel = 0;

public:

    SmartLight();
    void turnOn();
    void turnOff();
    void dim(int level);
    void printState();
    
    void setState(std::unique_ptr<LightState> newstate){
        state = std::move(newstate);
    }
    
};

#endif
