/*
I/P : 5
O/P :   5
        4
        3
        2
        1
         
*/

#include<iostream>
using namespace std;


void Display(int iNo)
{
    while(iNo >= 1)
    {
        cout<<iNo<<endl;
        iNo--;
    }
    
}

int main()
{
    int iValue = 0;

    cout<<"Enter number : "<<endl;
    cin>>iValue;

    Display(iValue);

    cout<<"End of application"<<endl;

    return 0;
}