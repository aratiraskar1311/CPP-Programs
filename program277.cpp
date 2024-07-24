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
     static int i = 1;           

    if(i <= iNo)            //using recursion
    {
        cout<<i<<endl;
        i++; 
        Display(iNo);                      
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