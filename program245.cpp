#include<iostream>
using namespace std;

int main()
{
    char Arr[30];
    
    cout<<"Enter your name :"<<endl;
    cin.getline(Arr, 30);                  //full name enter kela ki o/p yet nahi but special scanf used nahi krt cpp mdhe getline() used

    cout<<"Hello "<<Arr<<endl;

    return 0;
}

