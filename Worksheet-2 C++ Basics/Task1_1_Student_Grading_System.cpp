#include <iostream>
using namespace std;
class student {
public:
    string student_name;
    string three_subject[3]; 
    int three_subject_marks[3]; 
    
    void student_details() {
        cout << "Enter student name: ";
        cin >> student_name;
        cout << "Enter first subject: ";
        cin >> three_subject[0];
        cout << "Enter second subject: ";
        cin >> three_subject[1];
        cout << "Enter third subject: ";
        cin >> three_subject[2];
    }
    
    void student_marks() {
        cout << "Enter marks for first subject: ";
        cin >> three_subject_marks[0];
        cout << "Enter marks for second subject: ";
        cin >> three_subject_marks[1];
        cout << "Enter marks for third subject: ";
        cin >> three_subject_marks[2];
    }
    
    void total_marks() {
        int total = three_subject_marks[0] + three_subject_marks[1] + three_subject_marks[2];
        cout << "Total marks: " << total << endl;
        cout << "Average marks: " << total/3.0 << endl;
        if(total>=90){
            cout<<"you have grade A";
        }
        else if(total>= 80){
            cout<<"you have grade B";
        }
        else if(total>= 70){
            cout<<"you have grade C";
        }
        else if(total>= 60){
            cout<<"you have grade D";
        }
        else{
            cout<<"you have grade F";
        }
    }

};

int main() {
    student final;
    final.student_details();
    final.student_marks();
    final.total_marks();
    return 0;
}