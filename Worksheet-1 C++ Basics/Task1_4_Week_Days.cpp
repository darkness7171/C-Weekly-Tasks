#include <iostream>
using namespace std;
int main() {
    int day;
    while (true) {
        cout << "Enter day number (1-7, Sunday=1): ";
        cin >> day;
        if (day == 1) {
            cout << "Sunday" << endl;
            break;
        }
        else if (day == 2) {
            cout << "Monday" << endl;
            break;
        }
        else if (day == 3) {
            cout << "Tuesday" << endl;
            break;
        }
        else if (day == 4) {
            cout << "Wednesday" << endl;
            break;
        }
        else if (day == 5) {
            cout << "Thursday" << endl;
            break;
        }
        else if (day == 6) {
            cout << "Friday" << endl;
            break;
        }
        else if (day == 7) {
            cout << "Saturday" << endl;
            break;
        }
        else {
            cout << "Invalid day! Please try again." << endl;
        }
    }
    return 0;
}