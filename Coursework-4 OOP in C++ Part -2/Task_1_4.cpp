#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    void insertAtPosition(int val, int pos) {
        if (pos == 1) {
            insertAtStart(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* current = head;
        for (int i = 1; i < pos-1 && current; i++) {
            current = current->next;
        }
        if (!current) {
            cout << "Invalid position!\n";
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void findNthFromEnd(int n) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* first = head;
        Node* second = head;
        for (int i = 0; i < n; i++) {
            if (!first) {
                cout << "List is too short!\n";
                return;
            }
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        
        cout << n << "th node from end: " << second->data << endl;
    }
    void reverseGroups(int k) {
        head = reverseGroupHelper(head, k);
    }
    Node* reverseGroupHelper(Node* node, int k) {
        Node* current = node;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;
        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next) {
            node->next = reverseGroupHelper(next, k);
        }
        return prev;
    }
    void detectAndRemoveLoop() {
        if (!head || !head->next) {
            cout << "No loop found.\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                removeLoop(slow);
                cout << "Loop found and removed.\n";
                return;
            }
        }
        
        cout << "No loop found.\n";
    }
    void removeLoop(Node* loopNode) {
        Node* ptr1 = head;
        Node* ptr2 = loopNode;
        while (ptr1->next != ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = nullptr;
    }
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtStart(0);
    list.insertAtPosition(10, 3);
    cout << "Original list: ";
    list.display();
    cout << "2nd from end: ";
    list.findNthFromEnd(2);
    cout << "Reversing in groups of 2: ";
    list.reverseGroups(2);
    list.display();
    cout << "Checking for loops: ";
    list.detectAndRemoveLoop();
    return 0;
}