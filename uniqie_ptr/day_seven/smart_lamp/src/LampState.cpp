#include<iostream>
#include<memory>
#include "LampState.h"
#include "SmartLamp.h"

void LampState::turnOn(SmartLamp& lamp){
    lamp.getState()->turnOn(lamp);
}

void LampState::turnOff(SmartLamp& lamp){
    lamp.getState()->turnOff(lamp);
}
