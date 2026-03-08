#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle{
protected:
    int speed;

public:

    virtual void setSpeed(int s){
        speed = s;
    }

    int getSpeed(){
        return speed;
    }

    virtual void accelerate() = 0;
    virtual void printStatus() = 0;
    virtual ~Vehicle() = default;
};

#endif
