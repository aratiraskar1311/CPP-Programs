#include<iostream>
using namespace std;

void Display(int iNo)
{
    int iCnt = 0;
    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        cout<<"Jay Ganesh..."<<endl;
    }
}

int main()
{
    int iValue = 0;

    cout<<"enter the number you want to display :"<<endl;
    cin>>iValue;

    Display(iValue);

    return 0;
}