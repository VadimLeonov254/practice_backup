#ifndef RACE_H
#define RACE_H
#include<vector>
#include "Car.h"
#include "Driver.h"


class Race{

private:
    std::vector<std::shared_ptr<Driver>> drivers;

public:
    void startRace();
    void addDriver(std::shared_ptr<Driver>& driver);
};

#endif
