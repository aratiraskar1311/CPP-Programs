/*
I/P : no i/p
O/P :    *
         *
         *
         *
         
*/

#include<iostream>
using namespace std;

//Approach 5 : using recursion
void Display()
{
    static int i = 1;                     
    if(i <= 4)
    {
        cout<<"*"<<endl;
        i++;
        Display();                             //recursive call
    }
}

int main()
{
    Display();

    return 0;
}