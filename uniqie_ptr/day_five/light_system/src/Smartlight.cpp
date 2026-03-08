#include<iostream>
#include<memory>

#include "SmartLight.h"
#include "LightStates.h"
#include "OffState.h"
#include "OnState.h"
#include "DimState.h"


SmartLight::SmartLight(){
    state = std::make_unique<OffState>();
}

void SmartLight::turnOn(){
    state -> turnOn(*this);
}

void SmartLight::turnOff(){
    state -> turnOff(*this);
    dimLevel = 0;
}

void SmartLight::dim(int level){
    state -> dim(*this);
    dimLevel = level;
}

void SmartLight::printState(){
    state -> printState();

    if(dimLevel > 0){
        std::cout << "Dim level is " << dimLevel << '\n';
    }else if(dimLevel == 0){
        std::cout << '\n';
    }

}
