#ifndef COMMAND_H
#define COMMAND_H
#include "TaskManager.h"
class Command{

public:
    virtual void execute(TaskManager& manager) = 0;
    virtual void undo(TaskManager& manger) = 0;

};


#endif
