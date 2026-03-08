#include<iostream>
#include<memory>
#include "Command.h"
#include "TaskManager.h"
#include "UndoManager.h"
#include "AddTaskCommand.h"
#include "DeleteTaskCommand.h"

int main(){

    TaskManager myManager;
    UndoManager myUndoManager;

    auto add_a = std::make_unique<AddTaskCommand>("Task 1");
    auto add_b = std::make_unique<AddTaskCommand>("Task 2");
    auto del_a = std::make_unique<DeleteTaskCommand>("Task 1");

    add_a->execute(myManager);
    myUndoManager.addCommand(std::move(add_a));
    myManager.printTasks();

    add_b->execute(myManager);
    myUndoManager.addCommand(std::move(add_b));
    myManager.printTasks();

    del_a->execute(myManager);
    myUndoManager.addCommand(std::move(del_a));
    myManager.printTasks();

    myUndoManager.undo(myManager);
    myManager.printTasks();

    myUndoManager.undo(myManager);
    myManager.printTasks();

    myUndoManager.undo(myManager);
    myManager.printTasks();

}

