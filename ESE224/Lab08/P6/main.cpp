#include "BigNumber.h"
#include <iostream>
#include <fstream>

int main() {
    // Read two large numbers from a file named "numbers.txt"
    std::ifstream infile("numbers.txt");
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file numbers.txt\n";
        return 1;
    }

    std::string number1, number2;
    infile >> number1 >> number2;
    infile.close();

    // Create BigNumber objects
    BigNumber bigNum1(number1);
    BigNumber bigNum2(number2);

    // Display the numbers
    std::cout << "First Number: ";
    bigNum2.display();
    std::cout << "Second Number: ";
    bigNum1.display();

    // Perform addition
    BigNumber result = bigNum1.add(bigNum2);
    std::cout << "Sum: ";
    result.display();

    return 0;
}
