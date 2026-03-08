#include<iostream>
#include "Tool.h"

Tool::Tool(std::string name) : name(name){}

void Tool::use(){
    in_use = !in_use;
    if(in_use == true){
        std::cout << name << " is being used now";
    }else{
        std::cout << name << " is no longer in use";
    }
};

bool Tool::isUsed(){
    return in_use;
};

std::string Tool::getName(){
    return name;
}
