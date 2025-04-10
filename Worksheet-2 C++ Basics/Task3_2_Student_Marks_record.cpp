#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class student {
    int roll;
    string name;
    float marks;
public:
    student() : roll(0), name(""), marks(0.0f) {}  
    void getinput() {
        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter name: ";
        cin >> name;
        
        while(true) {
            cout << "Enter marks (0-100): ";
            cin >> marks;
            if(marks >= 0 && marks <= 100) break;
            cout << "Invalid marks! Must be between 0-100.\n";
        }
    }
    void display() { 
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
    void saveToFile() {
        ofstream file("students.txt", ios::app);
        if(file) {
            file << roll << " " << name << " " << marks << endl;
            cout << "Student saved to file!\n";
        } else {
            cout << "Error saving to file!\n";
        }
    }
    void readFromFile() {
        ifstream file("students.txt");
        if(file) {
            cout << "\nStudent Records:\n";
            while(file >> roll >> name >> marks) {
                display();
                cout << "--------\n";
            }
        } else {
            cout << "No records found!\n";
        }
    }
};

int main() {
    student s;
    int choice;
    do {
        cout << "\n1. Add new student\n";
        cout << "2. View all students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                s.getinput();
                s.saveToFile();
                break;
            case 2:
                s.readFromFile();
                break;
            case 3:
                cout << "Take care\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 3);
    
    return 0;
}