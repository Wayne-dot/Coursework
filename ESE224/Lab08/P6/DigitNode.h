#ifndef DIGITNODE_H
#define DIGITNODE_H

class DigitNode {
public:
    int digit;         // Single digit (0-9)
    DigitNode* next;   // Pointer to the next digit

    // Constructor
    DigitNode(int digit);
};

#endif // DIGITNODE_H
