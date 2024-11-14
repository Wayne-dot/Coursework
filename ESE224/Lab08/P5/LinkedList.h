#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Core Methods
    void insertAtEnd(int value);
    void display() const;
    void reverse();

    // Utility
    bool isEmpty() const;
};

#endif // LINKEDLIST_H
