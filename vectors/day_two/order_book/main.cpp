#include<iostream>
#include<vector>
#include<memory>
#include "Order.h"


int main(){
    
    std::cout << "Enter size of the order book: ";
    

    int num, size, id, price;
    
    std::cin >> size;

    std::vector<Order> orders(size, Order());
   
    std::cout << "How many orders do you want to place ?" << '\n';  
    std::cin >> num;

    for(int i = 0; i < num; i++){
        if (orders[i].getFlag() == false){
            if (i < 10){
                std::cout << "Order " << i+1 << " id: ";
                std::cin >> id;
                std::cout << "price: ";
                std::cin >> price;
                std::cout << '\n';
                orders[i] = Order(id, price);
            }
        }
    }

    for(int i = 0; i < orders.size()-1; i++){
        for(int k = 0; k < orders.size() - i - 1; k++){
            if(orders[k].getPrice() < orders[k+1].getPrice() && orders[k].getFlag() == true && orders[k+1].getFlag() == true){
                Order temp = orders[k];
                orders[k] = orders[k+1];
                orders[k+1] = temp;
            }
        }
    }


    for(int i = 0; i < 10; i++){
        if(orders[i].getFlag() == true){
            std::cout << orders[i].getId() << " " << orders[i].getPrice() << '\n';
        }
    }   
}
