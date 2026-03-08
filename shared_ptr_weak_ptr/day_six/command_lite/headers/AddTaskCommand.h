#ifndef ADDTASKCOMMAND_H
#define ADDTASKCOMMAND_H
#include "Command.h"
#include<string>

class AddTaskCommand : public Command{
private:
    std::string task;
public:
    AddTaskCommand(std::string task_enter);
    void execute(TaskManager& manager);
    void undo(TaskManager& manager);
};

#endif 
