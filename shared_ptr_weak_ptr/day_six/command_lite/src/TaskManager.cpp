#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include"TaskManager.h"

void TaskManager::addTask(const std::string& task){
    tasks.push_back(task);
}

void TaskManager::deleteTask(int taskId){
    tasks.erase(tasks.begin() + taskId);
}

void TaskManager::printTasks(){
    for(int i = 0; i < tasks.size(); i++){
        std::cout << i + 1 << ". " << tasks[i] << '\n';
    }
}

void TaskManager::popTask(const std::string& task){
    for(int i = 0; i < tasks.size(); i++){
        if(tasks[i] == task){
            tasks.erase(tasks.begin() + i);
        }
    }
}
