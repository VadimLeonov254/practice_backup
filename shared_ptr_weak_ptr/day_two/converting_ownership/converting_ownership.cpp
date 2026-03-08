#include<iostream>
#include<memory>


int main(){
    auto ptr_a = std::make_unique<int>(123);

    auto ptr_b = std::make_shared<int>();
    
    ptr_b = std::move(ptr_a);

    if(ptr_a == nullptr){
        std::cout << "ptr_a is empty now!" << '\n';
    }
    
    std::cout << *ptr_b << '\n';

}
