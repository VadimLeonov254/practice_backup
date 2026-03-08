#ifndef DELETETASKCOMMAND_H
#define DELETETASKCOMMAND_H
#include "Command.h"
#include<string>

class DeleteTaskCommand : public Command{
private:
    std::string task;
public:
    DeleteTaskCommand(std::string task_enter);
    void execute(TaskManager& manager);
    void undo(TaskManager& manager);
};

#endif
