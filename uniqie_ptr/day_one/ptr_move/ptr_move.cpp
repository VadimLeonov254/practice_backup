#include<iostream>
#include<memory>

int main(){
    
    std::unique_ptr<int> a = std::make_unique<int>(7);

    std::cout << "a currently holds " << *a << std::endl;

    std::unique_ptr<int> b;

    b = std::move(a);

    std::cout << "b currently holds " <<*b << std::endl;

    if(a == nullptr){
        std::cout << "a holds nothing now" << std::endl;
    }

}
