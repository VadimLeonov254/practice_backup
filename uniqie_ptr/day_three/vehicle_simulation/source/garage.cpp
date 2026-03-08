#include<memory>
#include<iostream>
#include "garage.h"


void Garage::addVehicle(std::unique_ptr<Vehicle> vehicle){
    garage.push_back(std::move(vehicle));
}

void Garage::accelerateAll(){
    for(int i = 0; i < garage.size(); i++){
        garage[i] -> accelerate();
    }
}

void Garage::printAll(){
    for(int i = 0; i < garage.size(); i++){
        std::cout << "Speed of the vehicle is " << garage[i] -> getSpeed() << std::endl;
    }
}
