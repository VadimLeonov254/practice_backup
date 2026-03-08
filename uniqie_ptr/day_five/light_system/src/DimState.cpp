#include<iostream>
#include<memory>

#include "LightStates.h"
#include "SmartLight.h"
#include "DimState.h"
#include "OffState.h"

void DimState::turnOn(SmartLight& light){
    std::cout << "Light is already on" << "\n\n";
}

void DimState::turnOff(SmartLight& light){
    light.setState(std::make_unique<OffState>());
}

void DimState::dim(SmartLight& light){
    light.setState(std::make_unique<DimState>());
}

void DimState::printState(){
    std::cout << "The light is dim" << '\n';
}
