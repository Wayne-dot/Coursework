// Sudoku.cpp
#include "Sudoku.h"
#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib> // for exit()

// Constructor to initialize the board from the input file
Sudoku::Sudoku(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        exit(1);
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            inputFile >> board[i][j];
        }
    }
    inputFile.close();
}

// Check if a row is valid
bool Sudoku::isValidRow(int row) {
    set<int> seen;
    for (int col = 0; col < 9; col++) {
        int num = board[row][col];
        if (num < 1 || num > 9 || seen.count(num)) {
            return false;
        }
        seen.insert(num);
    }
    return true;
}

// Check if a column is valid
bool Sudoku::isValidColumn(int col) {
    set<int> seen;
    for (int row = 0; row < 9; row++) {
        int num = board[row][col];
        if (num < 1 || num > 9 || seen.count(num)) {
            return false;
        }
        seen.insert(num);
    }
    return true;
}

// Check if a 3x3 subgrid is valid
bool Sudoku::isValidSubgrid(int startRow, int startCol) {
    set<int> seen;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = board[startRow + i][startCol + j];
            if (num < 1 || num > 9 || seen.count(num)) {
                return false;
            }
            seen.insert(num);
        }
    }
    return true;
}

// Check if the entire board is valid
bool Sudoku::isValid() {
    // Check all rows and columns
    for (int i = 0; i < 9; i++) {
        if (!isValidRow(i) || !isValidColumn(i)) {
            return false;
        }
    }

    // Check all 3x3 subgrids
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!isValidSubgrid(i, j)) {
                return false;
            }
        }
    }
    
    return true;
}
