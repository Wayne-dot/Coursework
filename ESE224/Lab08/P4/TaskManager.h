#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "TaskNode.h"
#include <iostream>
#include <string>

class TaskManager {
private:
    TaskNode* head;

public:
    // Constructor
    TaskManager();

    // Destructor
    ~TaskManager();

    // Core Methods
    void addTask(const std::string& description, const std::string& priority);
    void removeTask(const std::string& description);
    bool searchTask(const std::string& description) const;
    void displayTasks() const;
    int countTasks() const;

    // Utility Method
    void menu();
};

#endif // TASKMANAGER_H
