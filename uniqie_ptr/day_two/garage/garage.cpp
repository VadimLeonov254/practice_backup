#include<iostream>
#include<memory>

struct Car{
    int speed;
};

struct Garage{
    std::unique_ptr<Car> place;
};


int main(){
    
    Garage myGarage;

    std::unique_ptr<Car> nissan = std::make_unique<Car>();
   
   nissan -> speed = 100;

   myGarage.place = std::move(nissan);
    
    if(nissan == nullptr){
        std::cout << "nissan is empty now" << std::endl;
    }

}
