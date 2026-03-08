#include<iostream>

#include "circle.h"


Circle::Circle(int radius) : radius(radius){}

int Circle::getArea(){
    return radius * Circle::radius * 3.14;
}

int Circle::getCircumference(){
    return radius * 2 * 3.14;
}

int Circle::getRadius(){
    return radius;
}
