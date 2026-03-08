#include<iostream>
#include<memory>
#include<vector>

struct Car{

    std::string make;
};

struct Garage{

    std::vector<std::unique_ptr<Car>> gar;

};

int main(){

    auto toyota = std::make_unique<Car>();
    auto nissan = std::make_unique<Car>();
    auto porsche = std::make_unique<Car>();

    toyota -> make = "Toyota";
    nissan -> make = "Nissan";
    porsche -> make = "Porsche";

    Garage garage;
    Garage new_garage;
    garage.gar.push_back(std::move(toyota));
    garage.gar.push_back(std::move(nissan));
    garage.gar.push_back(std::move(porsche));

    for(int i = 0; i < garage.gar.size(); i++){
        std::cout << garage.gar[i] -> make << '\n';
    }

    for(int i = 0; i < garage.gar.size(); i++){
        new_garage.gar.push_back(std::move(garage.gar[i]));
    }
    std::cout << '\n';
    for(int i = 0; i < new_garage.gar.size(); i++){
        std::cout << new_garage.gar[i] -> make << '\n';
    }
}
