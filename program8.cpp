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
    bool EvenOdd()
    {
        if((iNo % 2) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int iValue = 0;
    bool bRet = 0;

    cout<<"Enter  number :"<<endl;
    cin>>iValue;

    Arithematic obj(iValue);
    bRet = obj.EvenOdd();

    if(bRet == true)
    {
        cout<<"Number is even "<<endl;
    }
    else
    {
        cout<<"Number is odd "<<endl;
    }
    

    return 0;
}
