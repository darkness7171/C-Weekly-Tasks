#include <iostream>
using namespace std;

class InvalidTimeException : public exception {
public:
    const char* what() const throw() {
        return "Error: Time must be between 00:00 and 23:59";
    }
};

class Time {
private:
    int hours;
    int minutes;

    void normalize() {
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }

public:
    Time(int h = 0, int m = 0) {
        if (h < 0 || h >= 24 || m < 0 || m >= 60) {
            throw InvalidTimeException();
        }
        hours = h;
        minutes = m;
    }

    Time operator+(const Time& other) const {
        Time temp(hours + other.hours, minutes + other.minutes);
        temp.normalize();
        return temp;
    }

    bool operator>(const Time& other) const {
        return (hours > other.hours) || 
               (hours == other.hours && minutes > other.minutes);
    }

    void display() const {
        if (hours < 10) cout << "0";
        cout << hours << ":";
        if (minutes < 10) cout << "0";
        cout << minutes;
    }

    static Time getTimeFromUser(const char* prompt) {
        int h, m;
        char sep;
        cout << prompt;
        cin >> h >> sep >> m;

        if (cin.fail() || sep != ':') {8
            throw runtime_error("Invalid input format. Please use HH:MM.");
        }

        return Time(h, m);
    }
};

int main() {
    try {
        cout << "Time Calculator\n";
        cout << "---------------\n";

        Time time1 = Time::getTimeFromUser("Enter first time (HH:MM): ");
        Time time2 = Time::getTimeFromUser("Enter second time (HH:MM): ");

        cout << "\nResults:\n";
        cout << "--------\n";

        cout << "First time: ";
        time1.display();
        cout << "\n";

        cout << "Second time: ";
        time2.display();
        cout << "\n";

        Time total = time1 + time2;
        cout << "Total time: ";
        total.display();
        cout << "\n";

        cout << "Comparison: ";
        if (time1 > time2) {
            time1.display();
            cout << " is later than ";
            time2.display();
        } else {
            time2.display();
            cout << " is later than ";
            time1.display();
        }
        cout << "\n";
    }
    catch (InvalidTimeException& e) {
        cerr << "\n" << e.what() << "\n";
    }
    catch (...) {
        cerr << "\nError: Invalid input format. Please enter time as HH:MM\n";
    }

    return 0;
}
