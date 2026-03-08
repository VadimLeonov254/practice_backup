#ifndef CAR_H
#define CAR_H
#include "vehicle.h"

class Car : public Vehicle{
private:
    int speed;
public:
    
        void accelerate();
    void printStatus();
};


#endif 
