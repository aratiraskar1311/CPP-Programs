#include<iostream>
using namespace std;

class Digit
{
    public:
        int iNo = 0;

    Digit(int A)
    {
        iNo = A;
    }
    void DisplayDigit()
    {
        int iDigit = 0;

        while(iNo > 0)
        {
            iDigit = iNo % 10;
            cout<<iDigit<<endl;
            iNo = iNo / 10;
        }
    }
};



int main()
{
    int iValue = 0;

    cout<<"Enter the number :"<<endl;
    cin>>iValue;

    Digit dobj(iValue);
    dobj.DisplayDigit();

    return 0;
}
