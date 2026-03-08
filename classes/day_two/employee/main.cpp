#include<iostream>
#include "employee.h"


int main(){
    
    double coef = 1.3;

    Employee goat("Pipioeah", 134);
    
    std::cout << goat.getName() << " makes " << goat.getSalary() << " money" << std::endl;
    
    goat.salaryChange(coef);

    std::cout << goat.getName() << " makes " << goat.getSalary() << " money" << std::endl;


}
