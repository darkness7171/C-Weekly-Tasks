#include <iostream>    
#include <vector>       
#include <map>         
#include <algorithm>  
using namespace std;
void addPerson(vector<string>& names, map<string, int>& ages, string name, int age) {
    names.push_back(name);    
    ages[name] = age;         
}
void findPeopleAboveAge(map<string, int>& ages, int m_age) {
    cout << "\n|||||||||- PEOPLE ABOVE AGE " << m_age << " -|||||||||" << endl;
    for (auto person : ages) {
        if (person.second > m_age) {
            cout << person.first << " (" << person.second << " years old)" << endl;
        }
    }
}
void displaySortedNames(vector<string> names) {
    sort(names.begin(), names.end());  
    cout << "\n|||||||||- SORTED NAMES -|||||||||" << endl;
    for (string name : names) {
        cout << name << endl;
    }
}
int main() {
    vector<string> names;
    map<string, int> ages;
    char choice;
    do {
        string name;
        int age;
        cout << "\nEnter name: ";
        cin >> ws;           
        getline(cin, name);  

        cout << "Enter age of " << name << ": ";
        cin >> age;

        addPerson(names, ages, name, age);

        cout << "Do you want to add another person? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    displaySortedNames(names);
    int ageLimit;
    cout << "\nEnter age to filter people above it: ";
    cin >> ageLimit;
    findPeopleAboveAge(ages, ageLimit);
    return 0;
}
