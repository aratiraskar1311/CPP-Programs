#include<iostream>
using namespace std;

class Pattern
{
    public:
        int iNo;

    Pattern(int A)
    {
        iNo = A;
    }
    int PatternDisplay()
    {   
        int iCnt = 0;
        for(iCnt = 1; iCnt <= iNo; iCnt++)
        {
            cout<<" "<<iCnt;
        }
    }

};

int main()
{
    int iValue = 0;
    
    cout<<"Enter the number :"<<endl;
    cin>>iValue;

    Pattern obj(iValue);
    obj.PatternDisplay();

    return 0;
}