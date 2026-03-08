#ifndef WORKSHOP_H
#define WORKSHOP_H
#include<vector>
#include "Tool.h"
#include "Worker.h"

class Workshop{
private:
    std::vector<std::shared_ptr<Tool>> tools;
 
public:
    void addTool(std::shared_ptr<Tool> tool);
    void removeTool(std::shared_ptr<Tool> tool);
    void assignTool(std::shared_ptr<Tool> tool, Worker& worker);
};

#endif
