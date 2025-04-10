#include<iostream>
using namespace std;
int main()
{
    int c,f,option;
    while (true)
    {
    cout<<" ---------------------------------------------- "<<endl;   
    cout<<" put 0 for converting temperature in fahrenheit "<<endl;
    cout<<" ---------------------------------------------- "<<endl;
    cout<<" put 1 for converting temperature in celcius "<<endl;
    cout<<" ---------------------------------------------- "<<endl;
    cout<<" enter the option you want for conversion: ";
    cin>>option;
    if(option == 0){
        cout<<"enter the tempereture value to convert in fahrenheit: ";
        cin>>c;
        cout<<"degree fahrenheit: "<<(c * 9/5) + 32<<endl;
        break;
       
    }
    else if (option == 1)
    {
        cout<<"enter the temperature valoe to convert in celcius: ";
        cin>>f;
        cout<<"degree celcius: "<<(f - 32) * 5/9<<endl;
        break;
    }
    
    else{
        cout<<" ----------------- "<<endl;
        cout<<" enter either 0 or 1"<<endl;
        cout<<" ----------------- "<<endl;
    }
}
    return 0;
}