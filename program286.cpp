/*
I/P : 7895
O/P :   5
        9
        8
        7

*/

#include<iostream>
using namespace std;

void Display(int iNo)
{
    int iDigit = 0;

    if(iNo != 0)
    {
        iDigit = iNo % 10;
        cout<<iDigit<<endl;
        iNo = iNo / 10;
        Display(iNo);
    }
}

int main()
{
    int iValue = 0;

    cout<<"Enter number : "<<endl;
    cin>>iValue;

    Display(iValue);

    return 0;
}