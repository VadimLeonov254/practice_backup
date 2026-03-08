#include<memory>
#include<iostream>
#include "car.h"


void Car::accelerate(){
    speed *= 1.25;
}

void Car::printStatus(){
    std::cout << "Current speed of the car is " << speed << std::endl;
}
