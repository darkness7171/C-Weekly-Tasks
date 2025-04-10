#include <iostream>
using namespace std;

class Circle {
private:
    float radius;
public:
    const float pie = 3.14; 
    float circle_one;        
    float circle_two;        

    void first_circle() {
        cout << "Enter the radius (in cm) for the first circle: ";
        cin >> radius;
        circle_one = pie * (radius * radius);
    }

    void second_circle() {
        cout << "Enter the radius (in cm) for the second circle: ";
        cin >> radius;
        circle_two = pie * (radius * radius);
    }

    void output() {
        if (circle_one > circle_two) {
            cout << "The first circle has a larger area: " << circle_one<< endl;
        } 
        else if (circle_two > circle_one) {
            cout << "The second circle has a larger area: " << circle_two << endl;
        } 
        else {
            cout << "Both circles have the same area: " << circle_one << endl;
        }
    }
};

int main() {
    Circle c1;
    c1.first_circle();
    c1.second_circle();
    c1.output();
    return 0;
}