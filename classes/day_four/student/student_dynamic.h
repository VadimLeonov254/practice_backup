#ifndef STUDENT_DYNAMIC_H
#define STUDENT_DYNAMIC_H

class Student{

private:
    std::string name;
    int age;
    double gpa;
public:
    
    Student(std::string name = "", int age = 0, double gpa = 0);    
   
    void studentInfo();

    void addName(std::string name);
    void addAge(int age);
    void addGpa(double gpa);
};


#endif 
