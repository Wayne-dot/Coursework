#include "Student.h"

// Constructor Implementation
Student::Student(const std::string& name, double grade)
    : name(name), grade(grade), next(nullptr) {}
