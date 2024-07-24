#include<iostream>
using namespace std;

float Average(int Arr[], int iSize)
{
    int i = 0;
    int iSum = 0;

    for(i = 0; i< iSize; i++)
    {
        iSum = iSum + Arr[i];

    }
    return ((float)iSum / (float)iSize);                    //typecasting
}

int main()
{
    int iLength = 0;
    int i = 0;
    float fRet = 0;
    int * ptr = NULL;

    cout<<"Enter number of elements that you want to store  : "<<endl;
    cin>>iLength;

    ptr = new int[iLength];

    cout<<"Enter the elements :"<<endl;
    for(i = 0; i < iLength; i++)
    {
        cin>>ptr[i];
    }
    
    fRet = Average(ptr,iLength);

    cout<<"Average is :" <<fRet<<endl;

    delete []ptr; 

    return 0;
}

