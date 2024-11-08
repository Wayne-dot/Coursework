// Theater.h
#ifndef THEATER_H
#define THEATER_H

#include <string>
using namespace std;

class Theater {
private:
    char seats[10][10];  // 10x10 seating grid

public:
    // Constructor to load seating chart from file
    Theater(const string& filename);

    // Destructor to save seating chart to file upon exit
    ~Theater();

    // Display the current seating arrangement
    void displaySeats() const;

    // Book a specific seat
    bool bookSeat(int row, int col);

    // Cancel a reservation for a specific seat
    bool cancelReservation(int row, int col);
};

#endif // THEATER_H
