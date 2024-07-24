//error yenar ch ya program la

#include<iostream>
using namespace std;

template<class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

    ArrayX(int no);
    ~ArrayX();
    void Accept();
    void Display();
    T Addition();
        
};

    ArrayX::ArrayX(int no)
    {
        iSize = no;
        Arr = new T [iSize];
    }
    ArrayX::~ArrayX()
    {
        delete []Arr;
    }

    void ArrayX::Accept()
    {
        int i = 0;

        cout<<"Enter the elements : \n";

        for(i = 0; i < iSize; i++)
        {
            cin>>Arr[i];
        }
        }

    void ArrayX::Display()
    {
        int i = 0;

            cout<<"Display the elements : \n";

            for(i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<"\n";
            }
        }

    T ArrayX::Addition()
    {
        int i = 0;
        T Sum = 0;

        for(i = 0; i < iSize; i++)
        {
                Sum = Sum + Arr[i];          
        }
        return Sum;
    }

int main()
{
    ArrayX <float>aobj(5);             //error solve

    aobj.Accept();
    aobj.Display();

    
    cout<<"Addition is : "<<aobj.Addition()<<"\n";

    return 0;
}