#include<iostream>
#include "Car.h"


Car::Car(std::string make) : make(make), fuel(100), speed(0){}

void Car::drive(){
    speed = 100;
    fuel = 0;
};

void Car::refuel(){
    speed = 0;
    fuel = 100;
};

int Car::getSpeed(){
    return speed;
};

int Car::getFuel(){
    return fuel;
};

std::string Car::getMake(){
    return make;
};
