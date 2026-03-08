#include<iostream>
#include<memory>
#include "Command.h"
#include "UndoManager.h"
#include "TaskManager.h"

void UndoManager::undo(TaskManager& manager){
    commands[commands.size()-1] -> undo(manager);
    commands.pop_back();
}

void UndoManager::addCommand(std::unique_ptr<Command> command){
    commands.push_back(std::move(command));
}
