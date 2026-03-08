#include<iostream>
#include<memory>

int main(){
    
    std::shared_ptr<int> ptr_a (new int (123));
    std::shared_ptr<int> ptr_b = ptr_a;
    std::shared_ptr<int> ptr_c = ptr_a;

    std::weak_ptr<int> ptr_obs = ptr_a;

    std::cout << ptr_a.use_count() << '\n';
    
    ptr_b.reset();
    std::cout << ptr_a.use_count() << '\n';

    std::shared_ptr<int> ptr_d = ptr_obs.lock();

    std::cout << ptr_a.use_count() << '\n';
    ptr_d.reset();
    std::cout << ptr_a.use_count() << '\n';


    

}
