#include <iostream>
using namespace std;
class Stack {
private:
    int arr[10];  
    int top;     
public:
    Stack() {
        top = -1;
    }
    bool isFull() {
        return top == 9;
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!\n";
        } else {
            top++;
            arr[top] = value;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            top--;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
    void findMiddle() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            int mid = top / 2;
            cout << "Middle element is: " << arr[mid] << endl;
        }
    }
    void reverseBottomHalf() {
        int size = top + 1;
        int mid = size / 2;

        for (int i = 0; i < mid / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[mid - 1 - i];
            arr[mid - 1 - i] = temp;
        }

        cout << "Bottom half reversed!\n";
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Stack (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;}
    }
};
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.display();        
    s.findMiddle();   
    s.reverseBottomHalf();
    s.display();        
    return 0;
}
