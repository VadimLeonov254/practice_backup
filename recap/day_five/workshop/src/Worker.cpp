#include<iostream>
#include<memory>
#include "Worker.h"
#include "Tool.h"

Worker::Worker(std::string name) : name(name) {}

void Worker::startTask(){
    if(auto t = tool.lock()){
        if(!t -> isUsed()){
            t -> use();
            std::cout << " by " << name << '\n';
        }else{
            std::cout << "Tool is already in use" << '\n';
        }
    }

};

void Worker::finishTask(){
    if(auto t = tool.lock()){
        if(!t -> isUsed()){
            t -> use();
            std::cout << " by " << name << '\n';
        }else{
            std::cout << "Tool was never used" << '\n';
         }
    }
};

void Worker::giveTool(std::shared_ptr<Tool> tool_main){
    tool = tool_main;
};
