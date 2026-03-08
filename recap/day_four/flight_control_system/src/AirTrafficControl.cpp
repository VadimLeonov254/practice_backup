#include<iostream>
#include<memory>
#include "AirTrafficControl.h"
#include "Pilot.h"

void AirTrafficControl::addPilot(std::shared_ptr<Pilot> pilot){
    pilots.push_back(pilot);
};


void AirTrafficControl::startFlights(){
    for(int i = 0 ; i < pilots.size(); i++){
        pilots[i] -> fly();
    }
}; 
