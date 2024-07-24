
#include<iostream>
using namespace std;

int main()
{
    int *ptr = NULL;
    int iLength = 0;
    int i = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    ptr = new int[iLength];

    cout<<"Enter the elements : \n";
    for(i = 0; i < iLength; i++)
    {
        cin>>ptr[i];
    }

    cout<<"Display the elements : "<<endl;
    for(i = 0; i < iLength; i++)
    {
        cout<<ptr[i]<<endl;
    }

    delete[]ptr;

    return 0;
}
