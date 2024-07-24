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
            cout<<"Display the elements :"<<endl;
            for(i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<endl;
            }

        }

        void CalculateDigits()
        {

            int i = 0;
            int iNo = 0;
            int iCount = 0;


            for(i = 0; i < iSize; i++)
            {
                //Arr[i];     single element nighto
                iNo = Arr[i];
                while(iNo != 0)
                {
                    iCount++;
                    iNo = iNo / 10;
                }
                cout<<Arr[i]<<" Contains "<<iCount<<" Digits in it"<<endl;
                iCount = 0;
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
    
    aobj->CalculateDigits();


    delete aobj;
    
    return 0;
}
