#ifndef PILOT_H
#define PILOT_H
#include "Plane.h"

class Pilot{
private:
    std::string name;
    Plane& plane;

public:
    Pilot(std::string name, Plane& plane);
    void fly();


};

#endif
