#include<iostream>
#include<memory>
#include "garage.h"
#include "factory.h"

int main(){
    
    Garage myGarage;
    Factory myFactory;
    

    myGarage.addVehicle(myFactory.createVehicle("bike", 2));
    myGarage.addVehicle(myFactory.createVehicle("car", 30));

    myGarage.accelerateAll();

    myGarage.printAll();

}  
