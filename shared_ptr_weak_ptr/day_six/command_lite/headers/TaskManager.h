#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include<vector>
#include<string>

class TaskManager{
private:
    std::vector<std::string> tasks;
public:
    void addTask(const std::string& task);
    void deleteTask(int taskId);
    void printTasks();
    void popTask(const std::string& task);
};

#endif
