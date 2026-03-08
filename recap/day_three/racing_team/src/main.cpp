#include<iostream>
#include<string>
#include<vector>
#include <memory>
#include "Car.h"
#include "Driver.h"
#include "Race.h"

int main() {
    auto car1 = std::make_unique<Car>("Toyota");
    auto car2 = std::make_unique<Car>("Honda");
    auto car3 = std::make_unique<Car>("BMW");

    auto d1 = std::make_shared<Driver>("Alex", *car1);
    auto d2 = std::make_shared<Driver>("Max", *car2);
    auto d3 = std::make_shared<Driver>("Leo", *car3);

    Race race;
    race.addDriver(d1);
    race.addDriver(d2);
    race.addDriver(d3);

    race.startRace();
}
