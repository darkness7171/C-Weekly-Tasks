#include <iostream>
#include <fstream>
using namespace std;
struct Student {
    int roll;
    string name;
    int marks;
};

bool validateMarks(int marks) {
    if (marks < 0 || marks > 100) {
        cout << "Invalid marks! Must be between 0-100.\n";
        return false;
    }
    return true;
}

void displayStudents(Student students[], int count) {
    cout << "\nCurrent Students:\n";
    for (int i = 0; i < count; i++) {
        cout << "Roll: " << students[i].roll 
             << ", Name: " << students[i].name 
             << ", Marks: " << students[i].marks << endl;
    }
}

int main() {
    const string filename = "students.txt";
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int count = 0;
    ifstream inFile(filename);
    if (inFile) {
        while (inFile >> students[count].roll >> ws && 
               getline(inFile, students[count].name, ',') && 
               inFile >> students[count].marks) {
            count++;
        }
        inFile.close();
    }
    displayStudents(students, count);
    char choice;
    do {
        cout << "\nAdd new student? (y/n): ";
        cin >> choice;
        
        if (tolower(choice) == 'y') {
            if (count >= MAX_STUDENTS) {
                cout << "Maximum students reached!\n";
                break;
            }

            cout << "Enter roll number: ";
            cin >> students[count].roll;
            
            cout << "Enter name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, students[count].name);
            
            cout << "Enter marks (0-100): ";
            cin >> students[count].marks;
            
            if (validateMarks(students[count].marks)) {
                count++;
            }
        }
    } while (tolower(choice) == 'y');

    ofstream outFile(filename);
    for (int i = 0; i < count; i++) {
        outFile << students[i].roll << " " 
                << students[i].name << "," 
                << students[i].marks << endl;
    }
    outFile.close();
    cout << "\nRecords saved to file. Goodbye!\n";
    return 0;
}