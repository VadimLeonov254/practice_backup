#include<iostream>
#include<memory>

struct Car{
    int speed;
};

void getSpeed(std::unique_ptr<Car> s){
    std::cout << s->speed << std::endl;
}

int main(){
    
    std::unique_ptr<Car> toyota = std::make_unique<Car>();
    

    toyota -> speed = 100;
    
    getSpeed(std::move(toyota));
    
    if(toyota == nullptr){
        std::cout << "Toyota has no speed now" << std::endl;
    }

}
