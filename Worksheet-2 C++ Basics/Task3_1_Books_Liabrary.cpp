#include<iostream>
#include<fstream>
using namespace std;
void forBooks(){
    char books[10][150];
    ofstream file("bks.bin");
    if (!file) {
        cout << "Error opening file!" << endl;
    }
    cin.ignore();
    for (int i = 0; i < 10; i++) { 
        cout << "Enter " << i + 1 << " book name: ";  
        cin.getline(books[i], 150); 
        file << i + 1 << ". " << books[i] << endl;  
    }
    
    file.close();
    cout << "Books have been saved to the file." << endl;
    
}
void forBooksdetails(){
    ifstream file("bks.bin");
    if(file.is_open()){
        string line;
        while(getline(file,line)){
        cout<<line<<endl;}
    }
}
void forBooksChecking(){
    ifstream file("bks.bin");
    char searchbook;
    cout<<"ENTER THE NAME OF THE BOOK YOU WANT TO SEARCH"<<endl;
    cin>>searchbook;
    char ch;
    bool found=false;
    while(file.get(ch)){
        if (ch==searchbook){
            found = true;
            break;
        }
    
    }
    if (found){
        cout<<"THE BOOKS IS IN LIBRARY!!"<<endl;
    }
    else
    cout<<"SORRY THE BOOKS IS NOT AVAILEABLE IN THE LIBARARY!"<<endl;
}
int main() {
    int option;
    cout<<"CHOOSE FROM BELOW"<<endl;
    cout<<"1.CHANGE BOOKS THAT ARE IN LIBRARY"<<endl;
    cout<<"2.CHECK BOOKS THAT ARE AVAILEABLE IN LIBRARY"<<endl;
    cout<<"3.CHECK IF TITLE IS AVAILEABLE IN LIBRARY"<<endl;
    cin>>option;
    if(option==1){
    forBooks();}
    else if(option==2){
    forBooksdetails();}
    else if (option==3){
        forBooksChecking();
    }
    return 0;
}
