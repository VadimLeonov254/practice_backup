#include<iostream>
#include<memory>
#include<vector>

struct Car{

    int speed;

};

int main(){
    
    std::unique_ptr<Car> volvo = std::make_unique<Car>();

    volvo -> speed = 100;

    std::unique_ptr<Car> nissan = std::make_unique<Car>();

    nissan -> speed = 200;

    std::vector<std::unique_ptr<Car>> catalog;

    catalog.push_back(std::move(volvo));
    catalog.push_back(std::move(nissan));
    
    for(int i = 0; i < 2; i++){
        std::cout << catalog[i]->speed << std::endl;
    }
    

}
