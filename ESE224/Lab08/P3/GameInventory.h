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

    // Add a new item
    void addItem(const std::string& name, const T& attribute, const double& value) {
        Item<T>* newItem = new Item<T>(name, attribute, value);
        if (head == nullptr) {
            head = newItem;
        } else {
            newItem->next = head;
            head = newItem; // Add to the beginning of the list (LIFO)
        }
        std::cout << "Item added successfully.\n";
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
            std::cout << "Name: " << temp->name
                      << ", Attribute: " << temp->attribute
                      << ", Value: $" << std::fixed << std::setprecision(2) << temp->value << "\n";
            temp = temp->next;
        }
    }

    // Retrieve the most recent item
    void retrieveMostRecentItem() const {
        if (head == nullptr) {
            std::cout << "Inventory is empty. No recent item to retrieve.\n";
            return;
        }
        std::cout << "Most Recent Item:\n";
        std::cout << "Name: " << head->name
                  << ", Attribute: " << head->attribute
                  << ", Value: $" << std::fixed << std::setprecision(2) << head->value << "\n";
    }

    // Calculate the total value of the inventory
    void totalInventoryValue() const {
        if (head == nullptr) {
            std::cout << "Inventory is empty. Total value is $0.00.\n";
            return;
        }
        double total = 0;
        Item<T>* temp = head;
        while (temp != nullptr) {
            total += temp->value;
            temp = temp->next;
        }
        std::cout << "Total Inventory Value: $" << std::fixed << std::setprecision(2) << total << "\n";
    }

    // Calculate the average attribute of items in the inventory
    void averageItemAttribute() const {
        if (head == nullptr) {
            std::cout << "Inventory is empty. Average attribute is 0.\n";
            return;
        }
        T totalAttribute = 0;
        int count = 0;
        Item<T>* temp = head;
        while (temp != nullptr) {
            totalAttribute += temp->attribute;
            count++;
            temp = temp->next;
        }
        std::cout << "Average Attribute Value: " << (static_cast<double>(totalAttribute) / count) << "\n";
    }

    // Clear the inventory
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
