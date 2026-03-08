#include<iostream>
#include<memory>

#include "mover.h"
#include "entity.h"

void Mover::linearMovement(Entity& object){
    
   object.setCoord(object.getvelX(), object.getvelY()); 

} 

void Mover::gravityMovement(Entity& object){
    
    object.setCoord(0, -9.8);

}

void Mover::frozenMovement(Entity& object){
    
}
