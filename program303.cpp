/* 
I/P  -  Enter number of elements : 4
        Enter the elements :    2
                                3  
                                4
                                5

O/P - Display elements are :    2
                                3  
                                4
                                5
*/

#include<iostream>
using namespace std;

int main()
{
    int *Arr = NULL;
    int iCount = 0;
    int i = 0;

    cout<<"Enter number of elements : "<<endl;
    cin>>iCount;

    Arr = new int[iCount];

    cout<<"Enter the elements :"<<endl;
    for(i = 0; i < iCount; i++)
    {
        cin>>Arr[i];
    }

    cout<<"Display elements are :"<<endl;
    for(i = 0; i < iCount; i++)
    {
        cout<<Arr[i]<<endl;
    }

    delete []Arr;

    return 0;
}