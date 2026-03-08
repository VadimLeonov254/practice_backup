#include<iostream>



struct Person{
    char name[50];
    int age;
};


int main(){
    Person* personPtr = new Person;


    std::cout << "Name: ";

    std::cin.getline(personPtr -> name, 50);

    std::cout << "Age: ";
    std::cin >> personPtr -> age;

    std::cout << "Your name is " << personPtr -> name << std::endl;
    std::cout << "Youre " << personPtr -> age << std::endl;

    delete personPtr;
}
