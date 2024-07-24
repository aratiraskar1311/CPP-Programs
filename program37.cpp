#include<iostream>
using namespace std;

class Arithematic
{
    public:
        int iNo = 0;
    
    Arithematic(int A)
    {
        iNo = A;
    }
    int FactorsCount()
    {
        int iCnt = 0;
        int iCount = 0;

        for(iCnt = 1; iCnt < iNo; iCnt++)
        {
            if((iNo % iCnt) == 0)
            {
                iCount++;
            }
        }
        return iCount;
    }
    
};


int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Entre the number:"<<endl;
    cin>>iValue;

    Arithematic obj(iValue);
    iRet = obj.FactorsCount();

    cout<<"Count total number of factors are :"<<iRet<<endl;

    return 0;
}