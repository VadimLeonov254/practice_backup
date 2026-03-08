#ifndef PLANE_H
#define PLANE_H

class Plane{
private:
    std::string model_name;

public:
    Plane(std::string model_name);
    void startEngine();
    void takeOff();
    void land();
    void stopEngine();
};

#endif
