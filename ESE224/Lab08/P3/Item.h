#ifndef ITEM_H
#define ITEM_H

#include <string>

template <typename T>
class Item {
public:
    std::string name;
    T attribute;   // Numeric attribute (e.g., power level or healing amount)
    double value;  // Cost or value of the item
    Item* next;

    // Constructor
    Item(const std::string& name, const T& attribute, const double& value)
        : name(name), attribute(attribute), value(value), next(nullptr) {}
};

#endif // ITEM_H
