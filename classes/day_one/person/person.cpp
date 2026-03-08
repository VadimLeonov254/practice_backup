#include<iostream>
#include "person.h"


Person::Person(int age, std::string name, std::string country) : age(age), name(name), country(country) {}


int Person::getAge(){
    return age;
}

std::string Person::getName(){
    return name;
}

std::string Person::getCountry(){
    return country;
}


void Person::setAge(int num){
    age = num;
}

void Person::setName(std::string nname){
    name = nname;
}

void Person::setCountry(std::string ccountry){
    country = ccountry;
}




