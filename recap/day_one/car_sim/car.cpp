#include<iostream>
#include "car.h"

Car::Car(std::string name, int speed, int fuel) : name(name), speed(speed), fuel(fuel){}


void Car::changeSpeed(int change){
    speed += change;
};

void Car::changeFuel(int amount){
    fuel += amount;
};

std::string Car::getName(){
    return name;
};

int Car::getSpeed(){
    return speed;
};

int Car::getFuel(){
    return fuel;
};

void Car::printCar(){
    std::cout << name << "'s speed is " << speed << " the fuel level is at " << fuel << '\n';
};
