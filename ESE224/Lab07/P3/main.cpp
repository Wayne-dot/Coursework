// main.cpp
#include <iostream>
#include "Sudoku.h"
using namespace std;

int main() {
    Sudoku sudoku("sudoku_input.txt");

    if (sudoku.isValid()) {
        cout << "The Sudoku board is valid!" << endl;
    } else {
        cout << "The Sudoku board is invalid." << endl;
    }

    return 0;
}
