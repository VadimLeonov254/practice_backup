#include<iostream>
#include<memory>
#include "OnState.h"
#include "LampState.h"
#include "SmartLamp.h"
#include "OffState.h"


void OnState::turnOn(SmartLamp& lamp){
    std::cout << "Lamp is already turned on" << "\n\n";
} 

void OnState::turnOff(SmartLamp& lamp){
    lamp.setState(std::make_unique<OffState>());
}

void OnState::printState(){
    std::cout << "The lamp is on!" << "\n\n"
}
