#include<iostream>
#include "Plane.h"
#include "Pilot.h"

Pilot::Pilot(std::string name, Plane& plane) : name(name), plane(plane) {}


void Pilot::fly(){
    plane.startEngine();
    plane.takeOff();
    plane.land();
    plane.stopEngine();
};
