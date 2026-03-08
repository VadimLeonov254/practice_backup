#include<iostream>
#include<memory>

void bsfunc(std::weak_ptr<int> ptr){
    if(ptr.expired() == 1){
        std::cout << "Object does not exist" << '\n';
    }else{
        auto ptr_a = ptr.lock();
        std::cout << *ptr_a << '\n';
    }
}

int main(){

    auto car = std::make_shared<int>(123);

    bsfunc(car);

    car.reset();

    bsfunc(car);

}
