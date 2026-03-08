#include<iostream>
#include<memory>

struct Car{
    int speed;
};

void printSpeed(const std::unique_ptr<Car>& car){
    std::cout << "Car has the speed of " << car->speed << std::endl;
}

int main(){
    int s;
    std::cout << "Enter the speed of the car: ";
    std::cin >> s; 
    std::unique_ptr<Car> volvo = std::make_unique<Car>();
    volvo->speed = s; 
    printSpeed(volvo);
}
