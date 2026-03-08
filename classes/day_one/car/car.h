#ifndef CAR_H
#define CAR_H

class Car{
private:
    int horsepower;
    int mass;

public:
    Car(int horsepower, int mass);
    int getHorsepower();
    int getMass();
    void increaseHorsepower(int horsepower);
};


#endif
