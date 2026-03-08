#ifndef MOVER_H
#define MOVER_H

#include "entity.h" 

class Entity;

class Mover{

private:
    std::unique_ptr<Entity> object;

public:
    
    void linearMovement(Entity& object);
    void gravityMovement(Entity& object);
    void frozenMovement(Entity& object);

};

#endif
