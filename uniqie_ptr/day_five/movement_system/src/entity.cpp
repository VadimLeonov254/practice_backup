#include<iostream>
#include<memory>

#include "entity.h"

Entity::Entity() : x(0), y(0) {}

void Entity::setCoord(float x_num, float y_num){
    x += x_num;
    y += y_num;
}

void Entity::setVel(float vx_num, float vy_num){
    vx = vx_num;
    vy = vy_num;
}

float Entity::getvelX(){
    return vx;
}
float Entity::getvelY(){
    return vy;
}

void Entity::getPos(){
    std::cout << x << " " << y << std::endl;
}
