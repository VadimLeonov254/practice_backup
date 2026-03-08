#ifndef GARAGE_H
#define GARAGE_H
#include<memory>
#include<vector>
#include "Car.h"

class Garage{
private:
    std::vector<std::unique_ptr<Car>> garage;

public:
    void refuelAll();
    void addCar(std::unique_ptr<Car> car);
};

#endif
