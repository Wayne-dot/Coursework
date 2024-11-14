#ifndef GAMEINVENTORY_H
#define GAMEINVENTORY_H

#include "Item.h"
#include <iostream>
#include <string>
#include <iomanip> // For formatting

template <typename T>
class GameInventory {
private:
    Item<T>* head;

public:
    // Constructor
    GameInventory() : head(nullptr) {}

    // Destructor
    ~GameInventory() { clear(); }

    // Add a new item to the inventory
    void addItem(const std::string& name, const T& attribute, const double& value) {
        Item<T>* newItem = new Item<T>(name, attribute, value);
        if (head == nullptr) {
            head = newItem;
        } else {
            newItem->next = head;
            head = newItem; // Add to the beginning (LIFO)
        }
    }

    // Remove the most recent item from the inventory
    void removeMostRecentItem() {
        if (head == nullptr) {
            std::cout << "Inventory is empty. No item to remove.\n";
            return;
        }
        Item<T>* temp = head;
        head = head->next;
        std::cout << "Removed item: " << temp->name << "\n";
        delete temp;
    }

    // Retrieve the most recent item without removing it
    void retrieveMostRecentItem() const {
        if (head == nullptr) {
            std::cout << "Inventory is empty. No recent item to retrieve.\n";
            return;
        }
        std::cout << "Most Recent Item:\n"
                  << "Name: " << head->name << ", Attribute: " << head->attribute
                  << ", Value: " << std::fixed << std::setprecision(2) << head->value << "\n";
    }

    // Display all items in the inventory
    void displayInventory() const {
        if (head == nullptr) {
            std::cout << "Inventory is empty.\n";
            return;
        }
        std::cout << "Inventory:\n";
        Item<T>* temp = head;
        while (temp != nullptr) {
            std::cout << "Name: " << temp->name << ", Attribute: " << temp->attribute
                      << ", Value: " << std::fixed << std::setprecision(2) << temp->value << "\n";
            temp = temp->next;
        }
    }

    // Calculate the total value of all items
    void totalValue() const {
        if (head == nullptr) {
            std::cout << "Inventory is empty. Total value is 0.\n";
            return;
        }
        double sum = 0;
        Item<T>* temp = head;
        while (temp != nullptr) {
            sum += temp->value;
            temp = temp->next;
        }
        std::cout << "Total Value of Inventory: " << std::fixed << std::setprecision(2) << sum << "\n";
    }

    // Calculate the average attribute of all items
    void averageAttribute() const {
        if (head == nullptr) {
            std::cout << "Inventory is empty. Average attribute is 0.\n";
            return;
        }
        T sum = 0;
        int count = 0;
        Item<T>* temp = head;
        while (temp != nullptr) {
            sum += temp->attribute;
            ++count;
            temp = temp->next;
        }
        std::cout << "Average Attribute: " << static_cast<double>(sum) / count << "\n";
    }

    // Clear all items from the inventory
    void clear() {
        while (head != nullptr) {
            Item<T>* temp = head;
            head = head->next;
            delete temp;
        }
        std::cout << "Inventory cleared.\n";
    }
};

#endif // GAMEINVENTORY_H
