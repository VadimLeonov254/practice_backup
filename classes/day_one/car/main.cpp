#include<iostream>

#include "car.h"

int main(){
    Car porsche (400, 1500);

    std::cout << "The car has " << porsche.getHorsepower() << " hp" << std::endl;
    std::cout << "The car weighs " << porsche.getMass() << " kg" << std::endl;

    porsche.increaseHorsepower(175);

    std::cout << "The car has " << porsche.getHorsepower() << " hp" << std::endl;


}
