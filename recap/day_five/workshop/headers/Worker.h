#ifndef WORKER_H
#define WORKER_H
#include<memory>
#include "Tool.h"

class Worker{
private:
    std::string name;
    std::weak_ptr<Tool> tool;
public:
    Worker(std::string name);
    void startTask();
    void finishTask();
    void giveTool(std::shared_ptr<Tool> tool_main);
};

#endif
