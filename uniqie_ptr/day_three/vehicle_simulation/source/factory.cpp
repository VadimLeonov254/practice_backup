#include<memory>
#include<iostream>
#include "factory.h" 
#include "bike.h"
#include "car.h"

std::unique_ptr<Vehicle> Factory::createVehicle(std::string type, int speed){
    
    std::unique_ptr<Vehicle> veh;
    

    if (type == "car"){
        veh = std::make_unique<Car>();
    } else if (type == "bike"){
        veh = std::make_unique<Bike>();
    }
    
    veh -> setSpeed(speed);

    return veh;

}
