#include<iostream>
#include<memory>
#include<vector>

struct Owner;

struct Car{
    std::string make;
    std::shared_ptr<Owner> owners;
};

struct Owner{
    
    std::string name;
    std::shared_ptr<Car> car;
    std::weak_ptr<Owner> partner;
};

int main(){

    auto ride = std::make_shared<Car>();
    auto Max = std::make_shared<Owner>();
    auto Alex = std::make_shared<Owner>();
    ride -> make = "Toyota";

    Max -> car = ride;
    Alex -> car = ride;
    
    ride -> owners = Max;
    ride -> owners = Alex;

    Max -> partner = Alex;
    Alex -> partner = Max;



}
