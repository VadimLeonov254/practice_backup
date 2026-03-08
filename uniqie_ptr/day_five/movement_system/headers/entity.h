#ifndef ENTITY_H
#define ENTITY_H

class Entity{

private:
    float x,y;
    float vx, vy;

public:
    Entity();

    void setCoord(float x_num, float y_num);

    void setVel(float vx_num, float vy_num);


    float getvelX();
    float getvelY();
    
    void getPos();
};
#endif
