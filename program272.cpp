/*
I/P : no i/p
O/P :    *
         *(infinite * print)
         
*/

#include<iostream>
using namespace std;

//Approach 4 : using recursion
void Display()
{
    int i = 1;                     //auto int i = 1;     (auto mule error yetoy so remove int,  auto i = 1; )
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