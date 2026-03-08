#include<iostream>
#include<vector>
#include<memory>
#include "car.h"

void increaseSpeed(Car& car, int change){
    
    car.changeSpeed(change);

}


int main(){

    std::vector<Car> garage;
    std::string ans = "yes";
    std::string name;
    int sp, fu;
    while(ans == "yes"){
        std::cout << "Do you want to add a new car?" << '\n';
        std::cin >> ans;
        if(ans == "no"){
            break;
        }else if(ans != "yes" && ans != "no"){
            std::cout << "Please enter yes or no" << '\n';
            std::cin >> ans;
        }
        std::cout << "Enter the name of the car: ";
        std::cin >> name;
        
        std::cout << "Enter the speed of the car: ";
        std::cin >> sp;

        std::cout << "Enter the amount of fuel car has";
        std::cin >> fu;
        Car car = Car(name, sp, fu);
        garage.push_back(car);
    }
    for(int i = 0; i < garage.size(); i++){
        increaseSpeed(garage[i], 100);
        std::cout << &garage[i] << '\n';
    }
   std::cout << garage.size() << '\n'; 
    

}
