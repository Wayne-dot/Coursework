#include "BigNumber.h"

// Constructor: Create a linked list of digits from a string
BigNumber::BigNumber(const std::string& number) : head(nullptr) {
    for (int i = number.length() - 1; i >= 0; --i) { // Start from the least significant digit
        int digit = number[i] - '0'; // Convert character to integer
        DigitNode* newNode = new DigitNode(digit);
        newNode->next = head;
        head = newNode;
    }
}

// Destructor: Free allocated memory
BigNumber::~BigNumber() {
    clear();
}

// Display the number
void BigNumber::display() const {
    if (!head) {
        std::cout << "0\n";
        return;
    }

    // Reverse the order for correct display
    DigitNode* temp = head;
    std::string number = "";
    while (temp != nullptr) {
        number = std::to_string(temp->digit) + number; // Append each digit
        temp = temp->next;
    }
    std::cout << number << "\n";
}

// Add two BigNumber objects
BigNumber BigNumber::add(const BigNumber& other) const {
    DigitNode* current1 = head;
    DigitNode* current2 = other.head;

    BigNumber result(""); // Initialize result with an empty number
    int carry = 0;

    while (current1 != nullptr || current2 != nullptr || carry != 0) {
        int sum = carry;

        if (current1 != nullptr) {
            sum += current1->digit;
            current1 = current1->next;
        }

        if (current2 != nullptr) {
            sum += current2->digit;
            current2 = current2->next;
        }

        carry = sum / 10; // Calculate carry for the next digit
        int digit = sum % 10;

        // Insert digit at the beginning of the result list
        DigitNode* newNode = new DigitNode(digit);
        newNode->next = result.head;
        result.head = newNode;
    }

    return result;
}

// Clear the linked list
void BigNumber::clear() {
    while (head != nullptr) {
        DigitNode* temp = head;
        head = head->next;
        delete temp;
    }
}
