#include<iostream>
#include<memory>
#include "SmartLamp.h"
#include "LampState.h"
#include "OnState.h"
#include "OffState.h"


void OffState::turnOn(SmartLamp& lamp){
    lamp.setState(std::make_unique<OnState>())
}

void OffState::turnOff(SmartLamp& lamp){
    std::cout << "The lamp is already turned off!" << "\n\n";
}

void OffState::printState(){
    std::cout << "The lamp is off" << "\n\n";
}
