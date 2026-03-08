#include<iostream>
#include<memory>
#include<vector>

struct Employee;

struct Manager_a{
   
    std::vector<std::shared_ptr<Employee>> employees;

    ~Manager_a(){
        std::cout << "Manager A. has been destroyed" << '\n';
    }

};

struct Manager_b{
    std::vector<std::shared_ptr<Employee>> employees;

    ~Manager_b(){
        std::cout << "Manager B. has been destroyed" << '\n';
    }
};

struct Employee{
   
    std::weak_ptr<Manager_a> managera; 
    std::weak_ptr<Manager_b> managerb;
    ~Employee(){
        std::cout << "Employee has been destroyed" << '\n';
    }
};

int main(){
    
    auto employee = std::make_shared<Employee>();
    auto manager_a = std::make_shared<Manager_a>();
    auto manager_b = std::make_shared<Manager_b>();
    
    employee -> managera = manager_a;
    manager_a -> employees.push_back(employee);
    
    manager_a -> employees.pop_back();
   
    employee -> managerb = manager_b;

    manager_b -> employees.push_back(employee);


}
