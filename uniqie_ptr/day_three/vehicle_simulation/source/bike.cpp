#include<memory>
#include<iostream>
#include "bike.h"


void Bike::accelerate(){
    speed *= 1.05;
}

void Bike::printStatus(){
    std::cout << "Current speed of the bike is " << speed << std::endl;
}
