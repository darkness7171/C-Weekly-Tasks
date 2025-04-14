#include <iostream>
using namespace std;
class Queue {
private:
    int arr[10];   
    int frnt;    
    int back;      
    int count;     
public:
    Queue() {
        frnt = 0;
        back = -1;
        count = 0;
    }
    bool isFull() {
        return count == 10;
    }
    bool isEmpty() {
        return count == 0;
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
        } else {
            back = (back + 1) % 10;
            arr[back] = value;
            count++;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
        } else {
            frnt = (frnt + 1) % 10;
            count--;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue (front to rear): ";
        for (int i = 0; i < count; i++) {
            int index = (frnt + i) % 10;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
    void reverseFirstK(int k) {
        if (k > count || k <= 0) {
            cout << "Invalid K!\n";
            return;
        }
        int tmp[10];
        for (int i = 0; i < k; i++) {
            tmp[i] = arr[(frnt + k - 1 - i) % 10];
        }
        for (int i = k; i < count; i++) {
            tmp[i] = arr[(frnt + i) % 10];
        }
        for (int i = 0; i < count; i++) {
            arr[(frnt + i) % 10] = tmp[i];
        }

        cout << "First " << k << " elements reversed!\n";
    }
    void interleaveQueue() {
        if (count % 2 != 0) {
            cout << "Need even number of elements to interleave!\n";
            return;
        }
        int half = count / 2;
        int tmp[10];
        for (int i = 0; i < half; i++) {
            tmp[i * 2] = arr[(frnt + i) % 10];
        }

        for (int i = 0; i < half; i++) {
            tmp[i * 2 + 1] = arr[(frnt + half + i) % 10];
        }
        for (int i = 0; i < count; i++) {
            arr[(frnt + i) % 10] = tmp[i];
        }
        cout << "Queue interleaved!\n";
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display(); 
    q.reverseFirstK(3);
    q.display();        
    q.interleaveQueue(); 
    q.display();     
    return 0;
}