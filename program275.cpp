/*
I/P : 5
O/P :   *
        *
        *
        *
        *
         
*/

#include<iostream>
using namespace std;

//Approach 6 : using recursion
void Display(int iNo)
{
    static int i = 1;           //executes only one time bcoz static

    if(i <= iNo)
    {
        cout<<"*"<<endl;
        i++;
        Display(iNo);                             //recursive call
    }
    cout<<"End of Display"<<endl;
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