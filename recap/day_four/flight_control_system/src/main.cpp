#include<iostream>
#include<memory>
#include<vector>
#include "Pilot.h"
#include "Plane.h"
#include "AirTrafficControl.h"

int main(){
 
    AirTrafficControl tower;

    auto plane1 = std::make_unique<Plane>("lol");
    auto plane2 = std::make_unique<Plane>("lmao");
    auto plane3 = std::make_unique<Plane>("wth");

    auto pilot1 = std::make_shared<Pilot>("Alex", *plane1);
    auto pilot2 = std::make_shared<Pilot>("Mayreen", *plane2);
    auto pilot3 = std::make_shared<Pilot>("Joey", *plane3);

    tower.addPilot(pilot1);
    tower.addPilot(pilot2);
    tower.addPilot(pilot3);

    tower.startFlights();


}
