#include<iostream>
#include<memory>
#include "Driver.h"
#include "Car.h"

Driver::Driver(std::string name, Car& car) : name(name), car(car) {}

std::string Driver::getName(){
    return name;
}

Car& Driver::getCar(){
    return car;
}

