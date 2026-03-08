#include<iostream>
#include<memory>
#include<vector>

struct Observer;
struct Subject{
    std::vector<std::weak_ptr<Observer>> observers;
};

struct Observer{
    int num;

    int getNum(){
        return num;
    }
};

int main(){

    
    auto observer_1 = std::make_shared<Observer>();
    auto observer_2 = std::make_shared<Observer>();
    
    observer_1 -> num = 1;
    observer_2 -> num = 2;
    
    auto subject = std::make_unique<Subject>();
    
    subject -> observers.push_back(observer_1);
    subject -> observers.push_back(observer_2);
    
    for(int i = 0; i < subject -> observers.size(); i++){
        if(subject -> observers[i].lock()){
            std::cout << subject -> observers[i].lock() -> getNum() << '\n';
        }
    }

}
