#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee{
private:
    std::string name;
    int id;
    double salary;
public:
    Employee(std::string name, double salary, int id = 1234);

    double getSalary();
    std::string getName();
    void salaryChange(double perfCoeff);
};


#endif 
