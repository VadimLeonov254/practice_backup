#ifndef CAR_H
#define CAR_H
#include<string>
class Car{

private:
    std::string name;
    int speed;
    int fuel;

public:
    Car(std::string, int speed, int fuel);
    void changeSpeed(int change);
    void changeFuel(int amount);    
    std::string getName();
    int getSpeed();
    int getFuel();
    void printCar();


};
#endif
