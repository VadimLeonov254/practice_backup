#include<iostream>
#include<memory>

int main(){
    
    std::shared_ptr<int> ptr_orig (new int(1234));

    std::weak_ptr<int> ptr_b = ptr_orig;
    
    std::shared_ptr<int> ptr_bc = ptr_b.lock();

    std::cout << ptr_orig.use_count() << '\n';

    

    std::cout << ptr_bc << '\n';
    std::cout << *ptr_bc << '\n';
    std::cout << ptr_bc.use_count() << '\n';
    
    ptr_bc.reset();

    std::cout << ptr_orig.use_count() << '\n';     
}
