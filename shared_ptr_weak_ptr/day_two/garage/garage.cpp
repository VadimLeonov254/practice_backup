#include<iostream>
#include<memory>

struct Car;

struct Engine{
};

struct Garage;

struct Car{
    std::unique_ptr<Engine> engine;
};

struct Garage{  
    std::weak_ptr<Car> car;
};

int main(){

    auto car = std::make_shared<Car>();
    auto engine = std::make_unique<Engine>();
    auto garage = std::make_shared<Garage>();

    car -> engine = std::move(engine);
    
    garage -> car = car;


}
