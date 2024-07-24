#include<iostream>
using namespace std;

class ArrayX
{
    public :
        int *Arr;
        int iSize;

        ArrayX(int No)
        {
            cout<<"Inside constructor"<<endl;
            iSize = No;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            cout<<"Inside destructor"<<endl;
            delete []Arr;
        }

        void Accept()
        {
            int i = 0;
            cout<<"Enter the elements :"<<endl;
            for(i = 0; i < iSize; i++)
            {
                cin>>Arr[i];
            }

        }

        void Display()
        {
            int i = 0;
            cout<<"Enter the elements :"<<endl;
            for(i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<endl;
            }

        }

        int SumDigits(int iNo)
        {
            int iSum = 0;
            int iDigit = 0;

            while(iNo != 0)
            {
                iDigit = iNo % 10;
                iSum = iSum + iDigit;
                iNo = iNo / 10;
            }
            return iSum;
        }

        void DisplayDigitSum()
        {
            int i = 0;
            int iRet = 0;

            for(i = 0; i < iSize; i++)
            {
                iRet =SumDigits(Arr[i]);
                cout<<"Display sum of Digits :"<<Arr[i]<<"is :"<<iRet<<endl;
            }
        }
        
};

int main()
{
    int iLength = 0;


    cout<<"Enter the number of elements that you wannt to store : "<<endl;
    cin>>iLength;

   // ArrayX aobj(iLength);                     static object creation
   ArrayX *aobj = new ArrayX(iLength);          //dynamic object creation


    aobj->Accept();
    aobj->Display();
    
    aobj->DisplayDigitSum();


    delete aobj;
    
    return 0;
}
