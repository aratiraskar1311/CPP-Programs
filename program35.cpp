#include<iostream>
using namespace std;

class Arithematic
{
    public :
        int iNo;
    Arithematic(int A)
    {
        iNo = A;
    }
    int SumFactor()
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
        return iSum;
    }
};


int main()
{

    int iValue = 0;
    int iRet = 0;

    cout<<"Enter the number :"<<endl;
    cin>>iValue;

    Arithematic obj(iValue);
    iRet = obj.SumFactor();

    cout<<"Summation of factors are : "<<iRet<<endl;

    return 0;
}