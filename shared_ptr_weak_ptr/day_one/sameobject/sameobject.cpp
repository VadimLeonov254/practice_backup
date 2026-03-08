#include<iostream>
#include<memory>

int main(){
    
    std::shared_ptr<int> ptr_a = std::make_shared<int>(5);
    
    std::shared_ptr<int> ptr_b = ptr_a;

    std::cout << *ptr_a << '\n';
    std::cout << ptr_a.get() << '\n';

    std::cout << *ptr_b << '\n';
    std::cout << ptr_b << '\n';

}
