#include<iostream>
#include "Order.h"

Order::Order(int id, int price) : id(id), price(price) {
    active_flag = true;
}

Order::Order(){}

int Order::getId(){
    return id;
}

int Order::getPrice(){
    return price;
}

bool Order::getFlag(){
    return active_flag;
}

void Order::changeFlag(){
    active_flag = !active_flag;
}
