#ifndef AIRTRAFFICCONTROL_H
#define AIRTRAFFICCONTROL_H
#include<vector>
#include "Pilot.h" 

class AirTrafficControl{
private:
    std::vector<std::shared_ptr<Pilot>> pilots;

public:
    void addPilot(std::shared_ptr<Pilot> pilot);
    void startFlights();
};

#endif
