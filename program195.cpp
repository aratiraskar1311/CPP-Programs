//Approach 3 using OOP

#include<iostream>
using namespace std;

class Arithematic
{   
    public:
        int iNo1;
        int iNo2;

        Arithematic(int A, int B)
        {
            iNo1 = A;
            iNo2 = B;
        }
        int Addition()
        {
            int iAns = 0;
            iAns = iNo1 + iNo2;
            return iAns;
        }

};

int main()
{
    int iValue1 = 0;
    int iValue2 = 0;
    int iRet = 0;

    cout<<"Enter first number : "<<endl;
    cin>>iValue1;

    cout<<"Enter second number : "<<endl;
    cin>>iValue2;

    Arithematic aobj(iValue1, iValue2);              //static object creation
    iRet = aobj.Addition();                         

    cout<<"Addition is : "<<iRet<<endl;    

    return 0;
}