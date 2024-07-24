/*
I/P : 7895
O/P :   5
        9
        8
        7

*/

#include<iostream>
using namespace std;

int Count(int iNo)
{
    int iCount = 0;

    while(iNo != 0)
    {
        iCount++;
        iNo = iNo / 10;
    }
    return iCount;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter number : "<<endl;
    cin>>iValue;

    iRet = Count(iValue);

    cout<<"Number of digit is :"<<iRet<<endl;

    return 0;
}