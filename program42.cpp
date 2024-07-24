#include<iostream>
using namespace std;

bool CheckPrime(int iNo)
{
    int iCnt = 0;
    int iCount = 0;
    
    for(iCnt = 2; iCnt < iNo; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iCount++;
            break;
        }
    }
    if(iCount == 0)
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
    bool bRet = false;

    cout<<"Enter the number :"<<endl;
    cin>>iValue;

    bRet = CheckPrime(iValue);

    if(bRet == true)
    {
        cout<<"number is prime "<<endl;
    }
    else
    {
        cout<<"number is not prime "<<endl;
    }   

    return 0;
}