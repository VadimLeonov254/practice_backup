#ifndef CIRCLE_H
#define CIRCLE_H

class Person{

private:
    int age;
    std::string name;
    std::string country;
public:

    Person(int age, std::string name, std::string country);
    
    int getAge();
    std::string getName();
    std::string getCountry();

    void setAge(int age);
    void setName(std::string name);
    void setCountry(std::string country);

};

#endif
