#include<iostream>
using namespace std;

bool CheckPerfect(int iNo)
{
    int iCnt = 0;
    int iSum = 0;

    for(iCnt = 1; iCnt < iNo; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter the number :"<<endl;
    cin>>iValue;

    iRet = CheckPerfect(iValue);

    if(iRet == true)
    {
        cout<<"Number is perfect "<<endl;
    }
    else
    {
        cout<<"Number is not perfect "<<endl;
    }
    

    return 0;
}