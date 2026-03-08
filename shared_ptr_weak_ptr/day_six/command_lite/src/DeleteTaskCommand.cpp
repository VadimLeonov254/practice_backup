#include<iostream>
#include<memory>
#include "Command.h"
#include "DeleteTaskCommand.h"
#include "TaskManager.h"

DeleteTaskCommand::DeleteTaskCommand(std::string task) : task(task){}

void DeleteTaskCommand::execute(TaskManager& manager){
    std::cout << "Task has been executed" << '\n';
    manager.popTask(task); 
}

void DeleteTaskCommand::undo(TaskManager& manager){
    std::cout << "Task has been undone" << '\n';
    manager.addTask(task);
}
