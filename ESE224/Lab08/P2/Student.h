#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    std::string name;
    double grade;
    Student* next;

    // Constructor
    Student(const std::string& name, double grade);
};

#endif // STUDENT_H
