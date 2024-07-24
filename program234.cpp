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

                while(iNo != 0)
                {
                    iSum = iSum + (iNo % 10);
                    iNo = iNo / 10;
                }
                return iSum;
        }

        void DisplayDigitsSum()
        {
            int i = 0, iRet = 0;

            for(i = 0; i < iSize; i++)
            {
                iRet = SumDigits(Arr[i]);
                cout<<"Sum of digits of "<<Arr[i]<<" is : "<<iRet<<endl;
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
    
    aobj->DisplayDigitsSum();


    delete aobj;
    
    return 0;
}
