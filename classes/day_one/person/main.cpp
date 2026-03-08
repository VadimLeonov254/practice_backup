#include<iostream>

#include "person.h"


int main(){

    Person max(21, "Max", "Italy");

    std::cout << max.getName() << std::endl;
    std::cout << max.getAge() << std::endl;
    std::cout << max.getCountry() << std::endl;

    max.setName("Alex");
    max.setAge(44);
    max.setCountry("Romania");

    std::cout << std::endl;

    std::cout << max.getName() << std::endl;
    std::cout << max.getAge() << std::endl;
    std::cout << max.getCountry() << std::endl;


}
