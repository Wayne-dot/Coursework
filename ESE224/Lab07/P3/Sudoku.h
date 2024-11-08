// Sudoku.h
#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
using namespace std;

class Sudoku {
private:
    int board[9][9];

public:
    // Constructor to initialize the board from the input file
    Sudoku(const string& filename);

    // Method to check if a row is valid
    bool isValidRow(int row);

    // Method to check if a column is valid
    bool isValidColumn(int col);

    // Method to check if a 3x3 subgrid is valid
    bool isValidSubgrid(int startRow, int startCol);

    // Method to check if the entire board is valid
    bool isValid();
};

#endif // SUDOKU_H
