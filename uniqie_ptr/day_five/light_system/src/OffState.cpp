#include<iostream>
#include<memory>

#include "SmartLight.h"  
#include "OnState.h"
#include "DimState.h" 
#include "OffState.h"
#include "LightStates.h"

void OffState::turnOn(SmartLight& light){
    light.setState(std::make_unique<OnState>());
}

void OffState::turnOff(SmartLight& light){
    std::cout << "Light is already off" << "\n\n";
}

void OffState::dim(SmartLight& light){
    light.setState(std::make_unique<DimState>());
}

void OffState::printState(){
    std::cout << "Light is off" << '\n';
} 
