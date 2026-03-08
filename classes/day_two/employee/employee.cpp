#include<iostream>
#include "employee.h"

Employee::Employee(std::string name, double salary, int id) : name(name), salary(salary), id(id) {}

double Employee::getSalary(){
    return salary;
}

std::string Employee::getName(){
    return name;
}

void Employee::salaryChange(double perfCoeff){
    salary *= perfCoeff;
}
