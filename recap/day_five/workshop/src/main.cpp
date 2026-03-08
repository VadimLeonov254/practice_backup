#include<iostream>
#include<memory>
#include<vector>
#include "Tool.h"
#include "Worker.h"
#include "Workshop.h"

int main() {
    Workshop myWorkshop;

    auto hammer = std::make_shared<Tool>("Hammer");
    auto wrench = std::make_shared<Tool>("Wrench");
    auto screwdriver = std::make_shared<Tool>("Screwdriver");

    myWorkshop.addTool(hammer);
    myWorkshop.addTool(wrench);
    myWorkshop.addTool(screwdriver);

    Worker Alex("Alex");
    Worker Sam("Sam");
    Worker Max("Max");

    myWorkshop.assignTool(hammer, Alex);
    Alex.startTask();

    myWorkshop.assignTool(hammer, Sam);
    Sam.startTask();

    myWorkshop.assignTool(wrench, Max);
    Max.startTask();

    myWorkshop.removeTool(wrench);

    Max.startTask();

    myWorkshop.assignTool(wrench, Sam);
    Sam.startTask();

    Alex.finishTask();
    myWorkshop.assignTool(hammer, Sam);
    Sam.startTask();

}

