/*
I/P : 7895
O/P :   4

*/



#include<iostream>
using namespace std;

int Count(int iNo)
{
    static int iCount = 0;

    if(iNo != 0)
    {
        iCount++;
        iNo = iNo / 10;
        Count(iNo);
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

    

