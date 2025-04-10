#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;
int main(){
    int user_number,option,random_number;
    while(true){
    cout<<" ....................................... "<<endl;  
    cout<<" Here are your option for guessing game: "<<endl;
    cout<<" ---------------------------------------"<<endl;  
    cout<<" 1. press 0 for easy level (0-8)"<<endl;
    cout<<" 2. press 1 for medium level (1-30)"<<endl;
    cout<<" 3. press 2 for hard level (1-50)"<<endl;
    cout<<" -----------------------------> "; 

    cin>>option;
 
    if(option==0){
        cout<<" enter the number you have in mind: ";
        cin>> user_number;
        srand(time(nullptr));
        int random_number = rand() % 8;
        if(random_number== user_number)
        {
            cout<< "well done! that was quite fun :) ";
        }
        else{
            cout<< "better luck next time T_T "<<endl;
            cout<< "the number was: "<< random_number;
        }
        break;
    }
    else if(option==1){
        cout<<" enter the number you have in mind: ";
        cin>> user_number;
        srand(time(nullptr));
        int random_number = rand() % 30;
        if(random_number== user_number)
        {
            cout<< "well done! that amazing :) ";
        }
        else{
            cout<< "better luck next time T_T "<<endl;
            cout<< "the number was: "<< random_number;
        }
        break;
    }
    else if(option==2){
        cout<<" enter the number you have in mind: ";
        cin>> user_number;
        srand(time(nullptr));
        int random_number = rand() % 50;
        if(random_number== user_number)
        {
            cout<< "well done! that was crazy :) ";
        }
        else{
            cout<< "better luck nest time T_T "<<endl;
            cout<< "the number was: "<< random_number;
        }
        break;
    }
    else{
        cout<<"enter the numbers between those options!!!"<<endl;
    }
}

return 0;
}