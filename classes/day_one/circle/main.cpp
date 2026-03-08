#include<iostream>

#include "circle.h"

int main(){

    Circle ball(15);

    std::cout << ball.getRadius() << std::endl;
    std::cout << ball.getArea() << std::endl;
    std::cout << ball.getCircumference() << std::endl;

}
