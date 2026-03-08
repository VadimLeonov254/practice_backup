#include<iostream>
#include "car.h"

int main(){
    
    Car* myCar = new Car("Toyota", 1999, 1234);
    
    myCar -> carInfo();
    
    delete myCar;
}
