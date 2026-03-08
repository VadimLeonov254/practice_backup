#include<iostream>
#include "car.h"


Car::Car(std::string brand, int year, double mileage) : brand(brand), year(year), mileage(mileage) {}

void Car::carInfo(){
    std::cout << "Car brand is " << brand << " and it was made in " << year << std::endl; 
}
