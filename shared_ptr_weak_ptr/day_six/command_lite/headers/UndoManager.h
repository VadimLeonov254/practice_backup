#ifndef UNDOMANAGER_H
#define UNDOMANAGER_H
#include<vector>
#include<memory>
#include "Command.h"
#include "TaskManager.h"

class UndoManager{
private:
    std::vector<std::unique_ptr<Command>> commands;
public:
    void undo(TaskManager& manager);
    void addCommand(std::unique_ptr<Command> command);
};

#endif
