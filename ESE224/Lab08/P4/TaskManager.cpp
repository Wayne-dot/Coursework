#include "TaskManager.h"

// Constructor
TaskManager::TaskManager() : head(nullptr) {}

// Destructor
TaskManager::~TaskManager() {
    while (head != nullptr) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Add a task to the end of the list
void TaskManager::addTask(const std::string& description, const std::string& priority) {
    TaskNode* newTask = new TaskNode(description, priority);

    if (head == nullptr) {
        head = newTask;
    } else {
        TaskNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
    std::cout << "Task added successfully.\n";
}

// Remove a task by description
void TaskManager::removeTask(const std::string& description) {
    TaskNode* current = head;
    TaskNode* previous = nullptr;

    while (current != nullptr) {
        if (current->description == description) {
            if (previous == nullptr) { // Removing head node
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            std::cout << "Task \"" << description << "\" removed successfully.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    std::cout << "Task \"" << description << "\" not found.\n";
}

// Search for a task by description
bool TaskManager::searchTask(const std::string& description) const {
    TaskNode* temp = head;
    while (temp != nullptr) {
        if (temp->description == description) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Display all tasks
void TaskManager::displayTasks() const {
    if (head == nullptr) {
        std::cout << "No tasks in the list.\n";
        return;
    }

    TaskNode* temp = head;
    std::cout << "Task List:\n";
    while (temp != nullptr) {
        std::cout << "Description: " << temp->description << ", Priority: " << temp->priority << "\n";
        temp = temp->next;
    }
}

// Count the total number of tasks
int TaskManager::countTasks() const {
    int count = 0;
    TaskNode* temp = head;
    while (temp != nullptr) {
        ++count;
        temp = temp->next;
    }
    return count;
}

// Menu for user interaction
void TaskManager::menu() {
    int choice;
    do {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Search Task\n";
        std::cout << "4. Display Tasks\n";
        std::cout << "5. Count Tasks\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string description, priority;
            std::cout << "Enter task description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            std::cout << "Enter task priority (High/Medium/Low): ";
            std::cin >> priority;
            addTask(description, priority);
            break;
        }
        case 2: {
            std::string description;
            std::cout << "Enter the description of the task to remove: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            removeTask(description);
            break;
        }
        case 3: {
            std::string description;
            std::cout << "Enter the description of the task to search: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            if (searchTask(description)) {
                std::cout << "Task \"" << description << "\" found.\n";
            } else {
                std::cout << "Task \"" << description << "\" not found.\n";
            }
            break;
        }
        case 4:
            displayTasks();
            break;
        case 5:
            std::cout << "Total number of tasks: " << countTasks() << "\n";
            break;
        case 6:
            std::cout << "Exiting Task Manager.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}
