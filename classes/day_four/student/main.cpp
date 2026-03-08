#include<iostream>
#include "student_dynamic.h"

int main(){
     
    std::string name;
    int age, numStudents;
    float gpa;
    std:: cout << "Enter the size of the class: ";
    std::cin >> numStudents; 

    Student* room = new Student[numStudents];

    for(int i = 0; i < numStudents; i++){
        std::cout << "Enter student's name: ";
        std::cin >> name;
        room[i].addName(name);
        std::cout << "Enter student's age: ";
        std::cin >> age;
        room[i].addAge(age);
        std::cout << "Enter student's GPA: ";
        std::cin >> gpa;    
        room[i].addGpa(gpa);
    }

    for(int k = 0; k < numStudents; k++){
        room[k].studentInfo();
        std::cout << std::endl;
    } 
    
    delete[] room;

        

}
