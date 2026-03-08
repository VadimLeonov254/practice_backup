#include<iostream>
#include "student_dynamic.h"

Student::Student(std::string name, int age, double gpa) : name(name), age(age), gpa(gpa) {}



void Student::studentInfo(){
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
    
}

void Student::addName(std::string newName){
    name = newName;
}

void Student::addAge(int newAge){
    age = newAge;
}

void Student::addGpa(double newGpa){
    gpa = newGpa;
}

