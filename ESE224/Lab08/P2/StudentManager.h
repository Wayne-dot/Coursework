#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <string>
#include "Student.h"

class StudentManager {
private:
    Student* head;

    // Helper to remove a student node
    bool removeNode(const std::string& name);

public:
    // Constructor and Destructor
    StudentManager();
    ~StudentManager();

    // Core Functions
    void loadFromFile(const std::string& filename);
    void addStudent(const std::string& name, double grade);
    void displayStudents() const;
    void calculateAverageGrade() const;
    void removeStudent(const std::string& name);

    // Menu Interface
    void menu();
};

#endif // STUDENTMANAGER_H
