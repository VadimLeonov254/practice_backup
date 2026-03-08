#include<iostream>
#include<memory>

int main(){
    
    std::shared_ptr<int> ptr_a = std::make_shared<int>(123);

    std::weak_ptr<int> ptr_b = ptr_a;

    std::cout << "Number of things that points to this object is " << ptr_a.use_count() << '\n';
    if(ptr_b.expired() == 0){
        std::cout << "Original object still exists" << "\n\n";
    }else{
        std::cout << "Original object no longet exists" << "\n\n";
    }

    ptr_a.reset();

    std::cout << "Number of things that points to this object is " << ptr_a.use_count() << '\n';
    if(ptr_b.expired() == 0){
        std::cout << "Original object still exists" << "\n\n";
    }else{
        std::cout << "Original object no longer exists" << "\n\n";
    }

}
