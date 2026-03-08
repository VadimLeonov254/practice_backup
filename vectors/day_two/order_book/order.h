#ifndef ORDER_H
#define ORDER_H

class Order{
private:
    int id;
    int price;
    bool active_flag = false;

public:
    Order(int id, int price);
    Order();
    int getId();
    int getPrice();
    bool getFlag();
    void changeFlag();
};

#endif
