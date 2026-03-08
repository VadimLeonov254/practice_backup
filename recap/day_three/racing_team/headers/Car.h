#ifndef CAR_H
#define CAR_H

class Car{

private:
    std::string make;
    int speed;
    int fuel;

public:
    
    Car(std::string make);
    void drive();
    void refuel();

    int getSpeed();
    int getFuel();
    std::string getMake();
};

#endif
