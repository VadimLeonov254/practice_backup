#include<iostream>
#include<memory>

struct Car{
    int mileage;
};

struct ServiceCenter{
    std::unique_ptr<Car> place;
};

ServiceCenter sendToService(std::unique_ptr<Car> car){
    ServiceCenter center;
    center.place = std::move(car);
    return center;
}

int main(){
    int m;
    std::cout << "Enter the mileage of your car: ";
    std::cin >> m;

    std::unique_ptr<Car> nissan = std::make_unique<Car>();

    nissan -> mileage = m;
    
    ServiceCenter myService;

    myService = sendToService(std::move(nissan));

    if(nissan == nullptr){
        std::cout << "Your nissan with the mileage of " << myService.place -> mileage << " is in the service" << std::endl;
    }
}
