#ifndef CAR_H
#define CAR_H


class Car{

private:
    std::string brand;
    int year;
    double mileage;
public:
    Car(std::string brand, int year, double mileage);

    void carInfo();
};

#endif
