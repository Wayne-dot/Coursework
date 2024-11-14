#ifndef ITEM_H
#define ITEM_H

#include <string>

template <typename T>
class Item {
public:
    std::string name;
    T attribute;       // Numeric attribute (e.g., weapon power, potion healing)
    double value;      // Cost or value of the item
    Item* next;        // Pointer to the next item in the linked list

    // Constructor
    Item(const std::string& name, const T& attribute, const double& value)
        : name(name), attribute(attribute), value(value), next(nullptr) {}
};

#endif // ITEM_H
