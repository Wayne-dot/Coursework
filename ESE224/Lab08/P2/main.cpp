#include "StudentManager.h"

int main() {
    StudentManager manager;

    // Load initial data from file
    std::string filename = "students.txt";
    manager.loadFromFile(filename);

    // Display the menu for user interaction
    manager.menu();

    return 0;
}
