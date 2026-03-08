#include<iostream>
#include<vector>
#include "Race.h"
#include "Car.h"
#include "Driver.h"

void Race::startRace(){
    for(int i = 0; i < drivers.size(); i++){
        drivers[i] -> getCar().drive();
    }    
};

void Race::addDriver(std::shared_ptr<Driver>& driver){
    drivers.push_back(driver);
};
