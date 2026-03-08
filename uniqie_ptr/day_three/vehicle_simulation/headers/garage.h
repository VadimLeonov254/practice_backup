#ifndef GARAGE_H
#define GARAGE_H
#include<vector>
#include "vehicle.h"

class Garage{
private:
    std::vector<std::unique_ptr<Vehicle>> garage;

public:
    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    void accelerateAll();

    void printAll();

};

#endif
