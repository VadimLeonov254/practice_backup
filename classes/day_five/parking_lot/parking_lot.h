#ifndef PARKING_LOT_H
#define PARKING_LOT_H

class Parking{

private:
    
    int size = 10;
    std::string* spot;


public:
    Parking();
    ~Parking();

    void addCar(int i, const std::string& owner);
    void getparkingLot();

};

#endif
