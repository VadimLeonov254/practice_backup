#include<iostream>
#include<memory>
#include "SmartLamp.h"
#include "LampState.h"
#include "OffState.cpp"


SmartLamp::SmartLamp(){
    state = std::make_unique<OffState>();
}

void SmartLamp::setState(std::unique_ptr<LampState> newstate){
    state = std::move(newstate);
}

std::unique_ptr<LampState> SmartLamp::getState(){
    return state;
}

void SmaerLamp::performTurnOn(){
    state -> turnOn(*this);
}

void SmartLamp::performTurnOff(){
    state -> turnOff(*this);
}

void SmartLamp::printStatus(){
    state -> printStatus();
}
