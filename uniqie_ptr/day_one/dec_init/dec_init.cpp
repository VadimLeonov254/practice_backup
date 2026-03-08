#include<iostream>
#include<memory>

int main(){
    
    int num;

    std::unique_ptr<int> ptr;
    
    ptr = std::make_unique<int>(5);
    
    std::cout << *ptr << std::endl;
    
    std::unique_ptr<int> ptrlol = std::make_unique<int>(10);

    std::cout << *ptrlol << std::endl;

    *ptrlol = 20;

    std::cout << *ptrlol << std::endl;

    std::unique_ptr<int> ptremm;

    if(ptremm == nullptr){
        std::cout << "Pointer is empty!" << std::endl;
    }

    if(!ptremm){
        std::cout << "Pointer is still empty!, but you can change it!" << std::endl << "Enter number: ";
    }
    std::cin >> num;

    ptremm = std::make_unique<int>(num);

    std::cout << "Congrats, the value its holding now is " << *ptremm << std::endl;

}
