#include<iostream>
#include "Plane.h"


Plane::Plane(std::string model_name): model_name(model_name) {}

void Plane::startEngine(){
    std::cout << "Engine has been started" << '\n';
};

void Plane::takeOff(){
    std::cout << "Plane has taken off" << '\n';
};

void Plane::land(){
    std::cout << "Plane has been landed safely" << '\n';
};

void Plane::stopEngine(){
    std::cout << "Engine has been stopped" << '\n';
};
