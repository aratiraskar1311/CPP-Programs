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
    int CountDigit()
    {
        int iDigit = 0;
        int iCount = 0;

        while(iNo > 0)
        {
            iDigit = iNo % 10;
            if(iDigit > 5)
            {
                iCount++;
            }
            iNo = iNo / 10;
        }
        return iCount;
    }
};

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter the value :"<<endl;
    cin>>iValue;

    Digit dobj(iValue);
    iRet =dobj.CountDigit();

    cout<<"count of all digits are :"<<iRet<<endl;

    return 0;
}