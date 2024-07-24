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
    void DisplayOddDigit()
    {
        int iDigit = 0;

        while(iNo > 0)
        {
            iDigit = iNo % 10;
            if((iDigit % 2) != 0)
            {
             cout<<iDigit<<endl;
            }
            iNo = iNo / 10;
        }
    }
};

int main()
{
    int iValue = 0;

    cout<<"Enter number :"<<endl;
    cin>>iValue;

    Digit dobj(iValue);
    dobj.DisplayOddDigit();

    return 0;
}