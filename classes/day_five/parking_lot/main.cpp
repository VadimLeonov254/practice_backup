#include<iostream>
#include "parking_lot.h"


int main(){

    Parking lot;
    int place;
    std::string name;
    lot.getparkingLot();
    
    std::cout << "What parking lot do you want to take? ";
    std::cin >> place;

    std::cout << "What is your last name ? ";
    std::cin >> name;

    lot.addCar(place-1, name);

    lot.getparkingLot();

}
