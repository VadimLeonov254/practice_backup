#include<iostream>
#include<memory>

struct Resource{
    
    int weight = 100;

};

struct Owner{
    std::shared_ptr<Resource> resource;
};

struct Observer{
    std::weak_ptr<Resource> observe;
};

int main(){
    
    auto res = std::make_shared<Resource>();
    auto owner = std::make_shared<Owner>();
    auto observer = std::make_shared<Observer>();

    owner -> resource = res;

    observer -> observe = res;

    if(observer -> observe.lock() -> weight == nullptr){
        std::cout << "Object does not exist" << '\n';
    }else{
        std::cout << observer -> observe.lock() -> weight << '\n';
    }
}
