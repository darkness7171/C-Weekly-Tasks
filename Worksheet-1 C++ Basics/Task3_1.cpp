#include <iostream>
using namespace std;

int main() {
    const int ROWS = 5;
    const int COLS = 5;
    char seats[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = 'O';
        }
    }
    cout << "Welcome to Cinema Ticket Booking System!\n";
    while (true) {
        cout << "\nCurrent Seating Arrangement:\n";
        cout << "  1 2 3 4 5\n";
        for (int i = 0; i < ROWS; i++) {
            cout << i+1 << " ";
            for (int j = 0; j < COLS; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        int row, col;
        cout << "Enter row and column (1-5) to book (0 0 to exit): ";
        cin >> row >> col;
        if (row == 0 && col == 0) {
            cout << "Thank you for using our booking system!\n";
            break;
        }
        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            cout << "Invalid seat selection! Please enter numbers between 1-5.\n";
            continue;
        }
        if (seats[row-1][col-1] == 'X') {
            cout << "Seat already booked! Please choose another seat.\n";
            continue;
        }
        seats[row-1][col-1] = 'X';
        cout << "Seat booked successfully!\n";
    }
    
    return 0;
}