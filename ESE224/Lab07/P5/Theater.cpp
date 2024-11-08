// Theater.cpp
#include "Theater.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constructor to load the seating chart from a file
Theater::Theater(const string& filename) {
    ifstream inputFile(filename);
    if (inputFile) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                inputFile >> seats[i][j];
            }
        }
        inputFile.close();
    } else {
        // Initialize all seats as available if file doesn't exist
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                seats[i][j] = 'O';
            }
        }
    }
}

// Destructor to save the seating chart to a file upon exit
Theater::~Theater() {
    ofstream outputFile("seating_chart.txt");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            outputFile << seats[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile.close();
}

// Display the current seating arrangement
void Theater::displaySeats() const {
    cout << "Seating Arrangement:\n";
    cout << "   ";
    for (int j = 0; j < 10; j++) {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << i << "  ";
        for (int j = 0; j < 10; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

// Book a specific seat
bool Theater::bookSeat(int row, int col) {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) {
        cout << "Invalid seat position." << endl;
        return false;
    }
    if (seats[row][col] == 'O') {
        seats[row][col] = 'X';
        cout << "Seat booked successfully!" << endl;
        return true;
    } else {
        cout << "Seat is already reserved." << endl;
        return false;
    }
}

// Cancel a reservation for a specific seat
bool Theater::cancelReservation(int row, int col) {
    if (row < 0 || row >= 10 || col < 0 || col >= 10) {
        cout << "Invalid seat position." << endl;
        return false;
    }
    if (seats[row][col] == 'X') {
        seats[row][col] = 'O';
        cout << "Reservation cancelled successfully!" << endl;
        return true;
    } else {
        cout << "Seat is already available." << endl;
        return false;
    }
}
