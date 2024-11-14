#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include "DigitNode.h"
#include <string>
#include <iostream>

class BigNumber {
private:
    DigitNode* head; // Points to the least significant digit (LSD)

public:
    // Constructor
    BigNumber(const std::string& number);

    // Destructor
    ~BigNumber();

    // Core Operations
    void display() const;
    BigNumber add(const BigNumber& other) const;

    // Utility
    void clear();
};

#endif // BIGNUMBER_H
