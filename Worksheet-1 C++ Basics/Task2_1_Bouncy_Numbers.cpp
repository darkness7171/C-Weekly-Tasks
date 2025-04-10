#include <iostream>
using namespace std;

int main() {
    int user_number;
    cout << "Enter a number (at least 3 digits): ";
    cin >> user_number;
    if (user_number < 100) {
        cout << "Too small - needs 3+ digits"; 
    }
    int n = user_number;
    bool up = false, down = false;
    int last = n % 10;
    n = n / 10;
    while (n > 0) {
        int current = n % 10;
        if (current < last) up = true;
        if (current > last) down = true;
        if (up && down) 
        break;
        last = current;
        n = n / 10;
    }
    if (up && down)
        cout << user_number << " is bouncy number!";
    else
        cout << user_number << " is not bouncy number";
    return 0;
}