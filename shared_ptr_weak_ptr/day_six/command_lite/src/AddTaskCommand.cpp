#include<iostream>
#include<memory>
#include "AddTaskCommand.h"
#include "Command.h"
#include "TaskManager.h" 
#include "UndoManager.h"

AddTaskCommand::AddTaskCommand(std::string task) : task(task){}

void AddTaskCommand::execute(TaskManager& manager){
    std::cout << "Task has been executed" << '\n';
    manager.addTask(task);
}

void AddTaskCommand::undo(TaskManager& manager){
    std::cout << "Task has been undone" << '\n';
    manager.popTask(task);
}
