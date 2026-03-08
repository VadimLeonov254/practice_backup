#include<iostream>
#include<memory>
#include<vector>
#include "Workshop.h"
#include "Worker.h"
#include "Tool.h"

void Workshop::addTool(std::shared_ptr<Tool> tool){
    tools.push_back(tool);
};

void Workshop::removeTool(std::shared_ptr<Tool> tool){
    bool is_found = false;
    for(int i = 0; i < tools.size(); i++){
        if(tools[i] -> getName() == tool -> getName()){
            tools.erase(tools.begin() + i);
            is_found = true;
        }
    }
    if(is_found){
        std::cout << "Tool has been removed" << '\n'; 
    }else{
        std::cout << "There is no such tool in the workshop" << '\n';
    }
};

void Workshop::assignTool(std::shared_ptr<Tool> tool, Worker& worker){
    worker.giveTool(tool);
};
