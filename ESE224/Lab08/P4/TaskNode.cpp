#include "TaskNode.h"

// Constructor implementation
TaskNode::TaskNode(const std::string& description, const std::string& priority)
    : description(description), priority(priority), next(nullptr) {}
