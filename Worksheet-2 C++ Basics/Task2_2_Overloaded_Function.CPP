#include<iostream>
using namespace std;

void findMax() {
    int a, b;
    cout << "PLEASE ENTER THE FIRST INTEGER: ";
    cin >> a;
    cout << "PLEASE ENTER THE SECOND INTEGER: ";
    cin >> b;
    if (a < b) {
        cout << "THE SECOND INTEGER IS MAXIMUM (" << b << ")" << endl;
    }
    else if (a > b) {
        cout << "THE FIRST INTEGER IS MAXIMUM (" << a << ")" << endl;
    }
    else {
        cout << "BOTH INTEGERS ARE EQUAL (" << a << ")" << endl;
    }
}

void findMax(float a, float b) {
    cout << "ENTER THE FIRST FLOATING-POINT NUMBER: ";
    cin >> a;
    cout << "ENTER THE SECOND FLOATING-POINT NUMBER: ";
    cin >> b;
    if (a > b) {
        cout << "THE FIRST FLOATING-POINT NUMBER IS LARGER (" << a << ")" << endl;
    }
    else if (b > a) {
        cout << "THE SECOND FLOATING-POINT NUMBER IS LARGER (" << b << ")" << endl;
    }
    else {
        cout << "BOTH FLOATING-POINT NUMBERS ARE EQUAL (" << a << ")" << endl;
    }
}

void findMax(int a, int b, int c) {
    cout << "PLEASE ENTER THE FIRST INTEGER: ";
    cin >> a;
    cout << "PLEASE ENTER THE SECOND INTEGER: ";
    cin >> b;
    cout << "PLEASE ENTER THE THIRD INTEGER: ";
    cin >> c;
    
    if (a >= b && a >= c) {
        cout << "THE FIRST INTEGER IS MAXIMUM (" << a << ")" << endl;
    }
    else if (b >= a && b >= c) {
        cout << "THE SECOND INTEGER IS MAXIMUM (" << b << ")" << endl;
    }
    else {
        cout << "THE THIRD INTEGER IS MAXIMUM (" << c << ")" << endl;
    }
}

void findMax(int a, float b) {
    cout << "PLEASE ENTER AN INTEGER: ";
    cin >> a;
    cout << "PLEASE ENTER A FLOATING-POINT NUMBER: ";
    cin >> b;
    
    if (a > b) {
        cout << "THE INTEGER IS LARGER (" << a << ")" << endl;
    }
    else if (b > a) {
        cout << "THE FLOATING-POINT NUMBER IS LARGER (" << b << ")" << endl;
    }
    else {
        cout << "BOTH NUMBERS ARE EQUAL (" << a << ")" << endl;
    }
}

int main() {
    cout<<"||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<" CHOOSE FROM GIVEN NUMBERS "<<endl;
    cout<<"1.MAXIMUM BETWEEN 2 INTEGERS"<<endl;
    cout<<"2.MAXIMUM BETWEEN 2 FLOATS.P"<<endl;
    cout<<"3.MAMXIMUM BETWEEN 3 INTEGERS"<<endl;
    cout<<"4.MAXIMUM BETWEEN FLOAT AND INTEGERS"<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    int a;
    cin>>a;
   if(a==1){
    findMax(); // Two integers (no args)
   }
   else if(a==2){
    float x, y;
    findMax(x, y); // Two floats
   }
   else if(a==3){
    int p, q, r;
    findMax(p, q, r); // Three integers
   }
   else if(a==4){
    int m;
    float n;
    findMax(m, n); // One int and one float
   }
   else{
    cout<<"please choose number form above!!! ";
   };
    
    return 0;
}