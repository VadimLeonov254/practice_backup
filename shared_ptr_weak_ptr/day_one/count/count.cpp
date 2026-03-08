#include<iostream>
#include<memory>

int main(){
        

    std::shared_ptr<int> ptr_a (new int(123));
    
    std::cout << *ptr_a << '\n';
    std::cout << ptr_a.use_count() << '\n';
    
    std::shared_ptr<int> ptr_b = ptr_a;

    std::cout << *ptr_a << '\n';
    std::cout << ptr_a.use_count() << '\n';
    
    ptr_b.reset();

    std::cout << *ptr_a << '\n';
    std::cout << ptr_a.use_count() << '\n';
    

}
