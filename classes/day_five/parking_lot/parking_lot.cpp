#include<iostream>
#include "parking_lot.h"

Parking::Parking(){
    spot = new std::string[size];
    
    for(int i = 0; i < size; i++){
        spot[i] = "Empty";
    }
}

Parking::~Parking(){
    delete[] spot;
}


void Parking::addCar(int i, const std::string& owner){

    if(spot[i] == "Empty"){
        spot[i] = owner;
    }else{
        std::cout << "This spot is taken" << std::endl;
    }

}

void Parking::getparkingLot(){
    std::cout << std::endl;
    for(int i = 0; i < size; i++){
        if(spot[i] == "Empty"){
            std::cout << "Parking lot " << i+1 << " is empty" << std::endl;
        }
        else{
            std::cout << "Parking lot " << i+1 << " is taken by " << spot[i] << std::endl; 
        }
    }
    std::cout << std::endl;
}
