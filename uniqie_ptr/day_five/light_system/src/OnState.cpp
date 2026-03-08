#include<iostream>
#include<memory>

#include "OnState.h"
#include "SmartLight.h"
#include "LightStates.h"
#include "OffState.h"
#include "DimState.h"
#include "OnState.h" 

void OnState::turnOn(SmartLight& light){
    std::cout << "Light is already on" << "\n\n";   
}

void OnState::turnOff(SmartLight& light){
    light.setState(std::make_unique<OffState>());
}

void OnState::dim(SmartLight& light){
    light.setState(std::make_unique<DimState>());
}

void OnState::printState(){ 
    std::cout << "Light is on!" << '\n';
};
