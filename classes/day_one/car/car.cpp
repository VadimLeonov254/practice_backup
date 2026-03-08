#include<iostream>
#include "car.h"


Car::Car(int horsepower, int mass) : horsepower(horsepower), mass(mass){}

int Car::getHorsepower(){
    return horsepower;
}

int Car::getMass(){
    return mass;
}

void Car::increaseHorsepower(int increase){
    Car::horsepower += increase;
}
