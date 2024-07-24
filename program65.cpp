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
    void ReverseDigit()
    
    {
        int iDigit = 0;
        int iRev = 0;

        while(iNo > 0)
        {
            iDigit = iNo % 10;
            iRev = (iRev * 10) + iDigit;
            iNo = iNo / 10;
        }
        return iRev;
    }

};

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter the number :"<<endl;
    cin>>iValue;

    Digit dobj(iValue);
    iRet = dobj.ReverseDigit();

    cout<<"Reverse number is :"<<iRet<<endl;

    return 0;
}