/*
I/P - Enter number : 5678

O/P -  Sum of digit is :8

*/

#include<iostream>
using namespace std;

int SumDigits(int iNo)
{
     int iSum = 0;

    if(iNo != 0)
    {
        iSum = iSum + (iNo % 10);
        SumDigits(iNo/10);
    }
    return iSum;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter number : "<<endl;
    cin>>iValue;

    iRet = SumDigits(iValue);

    cout<<"Sum of digit is :"<<iRet<<endl;

    return 0;
}