#include "LinkedList.h"
#include <iostream>
#include <fstream>

int main() {
    LinkedList list;

    // Read integers from an input file named "input.txt"
    std::ifstream infile("input.txt");
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file input.txt\n";
        return 1;
    }

    int value;
    std::cout << "Reading values from input.txt and inserting into the list...\n";
    while (infile >> value) {
        list.insertAtEnd(value);
    }
    infile.close();

    // Display the list before reversing
    std::cout << "Linked List before reversing:\n";
    list.display();

    // Reverse the linked list
    list.reverse();

    // Display the list after reversing
    std::cout << "Linked List after reversing:\n";
    list.display();

    return 0;
}
