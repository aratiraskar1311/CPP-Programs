#include<iostream>
using namespace std;

class Digit
{
    public:
        int iNo;
    Digit(int A)
    {
        iNo = A;
    }
    int SumDigits()
    {
        int iDigit = 0;
        int iSum = 0;

        while(iNo > 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
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

    Digit dobj(iValue);
    iRet =dobj.SumDigits();

    cout<<"Sum of all digits are :"<<iRet<<endl;

    return 0;
}