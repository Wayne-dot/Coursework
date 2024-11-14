#include "StudentManager.h"
#include <iostream>
#include <fstream>

// Constructor
StudentManager::StudentManager() : head(nullptr) {}

// Destructor
StudentManager::~StudentManager() {
    while (head != nullptr) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper to remove a node
bool StudentManager::removeNode(const std::string& name) {
    Student* current = head;
    Student* previous = nullptr;

    while (current != nullptr) {
        if (current->name == name) {
            if (previous == nullptr) { // Removing head node
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

// Load students from file
void StudentManager::loadFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    int numStudents;
    infile >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        double grade;
        infile >> name >> grade;
        addStudent(name, grade);
    }
    infile.close();
}

// Add a student
void StudentManager::addStudent(const std::string& name, double grade) {
    Student* newStudent = new Student(name, grade);

    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Display all students
void StudentManager::displayStudents() const {
    if (head == nullptr) {
        std::cout << "No students in the list.\n";
        return;
    }

    std::cout << "Student Records:\n";
    Student* temp = head;
    while (temp != nullptr) {
        std::cout << "Name: " << temp->name << ", Grade: " << temp->grade << "\n";
        temp = temp->next;
    }
}

// Calculate average grade
void StudentManager::calculateAverageGrade() const {
    if (head == nullptr) {
        std::cout << "No students to calculate the average grade.\n";
        return;
    }

    double sum = 0;
    int count = 0;
    Student* temp = head;

    while (temp != nullptr) {
        sum += temp->grade;
        ++count;
        temp = temp->next;
    }

    std::cout << "Class Average Grade: " << (sum / count) << "\n";
}

// Remove a student
void StudentManager::removeStudent(const std::string& name) {
    if (removeNode(name)) {
        std::cout << "Student \"" << name << "\" removed successfully.\n";
    } else {
        std::cout << "Student \"" << name << "\" not found in the records.\n";
    }
}

// Menu
void StudentManager::menu() {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display all students\n";
        std::cout << "2. Show class average grade\n";
        std::cout << "3. Add a new student\n";
        std::cout << "4. Remove a student by name\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayStudents();
            break;
        case 2:
            calculateAverageGrade();
            break;
        case 3: {
            std::string name;
            double grade;
            std::cout << "Enter student name: ";
            std::cin >> name;
            std::cout << "Enter student grade: ";
            std::cin >> grade;
            addStudent(name, grade);
            break;
        }
        case 4: {
            std::string name;
            std::cout << "Enter the name of the student to remove: ";
            std::cin >> name;
            removeStudent(name);
            break;
        }
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}
