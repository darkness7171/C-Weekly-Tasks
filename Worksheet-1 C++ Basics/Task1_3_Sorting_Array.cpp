#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int SIZE = 10;
    int a[SIZE];
    

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter element " << i << ": ";
        cin >> a[i];
    }
    sort(a, a + SIZE);
    cout << "\nSorted array in ascending order:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}