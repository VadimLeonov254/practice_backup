#include<iostream>
#include<memory>

struct Car{
    int speed;
};

struct Garage{
    std::unique_ptr<Car> place;
};


Garage buildGarage(std::unique_ptr<Car> car){
    
    Garage myGarage;

    myGarage.place = std::move(car);

    return myGarage;
}

int main(){

    std::unique_ptr<Car> toyota = std::make_unique<Car>();

    toyota -> speed = 150;

    Garage newGarage = buildGarage(std::move(toyota));
    
    std::cout << newGarage.place -> speed << std::endl;

    if(toyota == nullptr){
        std::cout << "Toyota is empty" << std::endl;
    } 

}
