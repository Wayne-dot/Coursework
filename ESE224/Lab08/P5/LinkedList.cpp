#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() : head(nullptr) {}

// Destructor
LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Insert a new node at the end of the list
void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display the linked list
void LinkedList::display() const {
    if (head == nullptr) {
        std::cout << "The list is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Reverse the linked list
void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Store next
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one step forward
        current = next;
    }

    head = prev; // Update head to the new first element
}

// Check if the list is empty
bool LinkedList::isEmpty() const {
    return head == nullptr;
}
