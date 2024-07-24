/*
I/P : 5
O/P :   1
        2
        3
        4
        5
         
*/

#include<iostream>
using namespace std;


void Display(int iNo)
{
     int i = 1;           

    while(i <= iNo)         //using while loop
    {
        cout<<i<<endl;
        i++;                       
    }
    
}

int main()
{
    int iValue = 0;

    cout<<"Enter number : "<<endl;
    cin>>iValue;

    Display(iValue);

    cout<<"End of application"<<endl;

    return 0;
}