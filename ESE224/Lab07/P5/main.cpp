// main.cpp
#include <iostream>
#include "Theater.h"
using namespace std;

int main() {
    Theater theater("seating_chart.txt");

    int choice;
    while (true) {
        cout << "\nMovie Ticket Booking System\n";
        cout << "1. Display Seating Arrangement\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel a Reservation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            theater.displaySeats();
        } else if (choice == 2) {
            int row, col;
            cout << "Enter row and column to book (0-9): ";
            cin >> row >> col;
            theater.bookSeat(row, col);
        } else if (choice == 3) {
            int row, col;
            cout << "Enter row and column to cancel (0-9): ";
            cin >> row >> col;
            theater.cancelReservation(row, col);
        } else if (choice == 4) {
            cout << "Exiting the program..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
