#include<iostream>
using namespace std;


class Arithematic
{
    public:
        int iNo;
    Arithematic(int A)
    {
        iNo = A;
    }
    int Factorial()
    {
        int iCnt = 0;
        int iMult = 1;

        for(iCnt = 1; iCnt <= iNo; iCnt++)
        {
            iMult = iMult * iCnt;
        }
        return iMult;
    }
};


int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter the number : "<<endl;
    cin>>iValue;

    Arithematic obj(iValue);
    iRet = obj.Factorial();

    cout<<"Factorial is :"<<iRet<<endl;

    return 0;
}