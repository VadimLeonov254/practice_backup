#ifndef DRIVER_H
#define DRIVER_H
#include<memory>
#include "Car.h"

class Driver{
private:
    std::string name;
    Car& car;

public:
    Driver(std::string name, Car& car);
    std::string getName();
    Car& getCar();

};

#endif
