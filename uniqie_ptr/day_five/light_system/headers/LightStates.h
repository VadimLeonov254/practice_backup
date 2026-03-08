#ifndef LIGHTSTATE_H
#define LIGHTSTATE_H

class SmartLight;

class LightState{


public:
    
    virtual void turnOn(SmartLight& light) = 0;
    virtual void turnOff(SmartLight& light) = 0;
    virtual void dim(SmartLight& light) = 0;
    virtual void printState() = 0;
    

    virtual ~LightState() = default;    

};

#endif
