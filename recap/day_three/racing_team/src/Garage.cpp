#include<iostream>
#include<vector>
#include<memory>
#include "Garage.h"
#include "Car.h"


void Garage::refuelAll(){
    for(int i = 0; i < garage.size(); i++){
        garage[i] -> refuel();  
    }
};

void Garage::addCar(std::unique_ptr<Car> car){
    garage.push_back(std::move(car));
};
