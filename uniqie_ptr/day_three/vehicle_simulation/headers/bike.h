#ifndef BIKE_H
#define BIKE_H
#include "vehicle.h" 


class Bike : public Vehicle{

private:
    int speed;

public:

    void accelerate();
    void printStatus();

};


#endif
