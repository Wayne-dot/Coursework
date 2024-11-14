#ifndef TASKNODE_H
#define TASKNODE_H

#include <string>

class TaskNode {
public:
    std::string description;
    std::string priority; // "High", "Medium", or "Low"
    TaskNode* next;

    // Constructor
    TaskNode(const std::string& description, const std::string& priority);
};

#endif // TASKNODE_H
