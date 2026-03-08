#ifndef FACTORY_H
#define FACTORY_H

#include "vehicle.h" 

class Factory{
public:
    std::unique_ptr<Vehicle> createVehicle(std::string type, int speed); 
};

#endif
