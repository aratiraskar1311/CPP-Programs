/*
I/P : no i/p
O/P :    * 
         
*/

#include<iostream>
using namespace std;

//Approach 3 : using recursion              (but no recursion used)
void Display()
{
    int i = 1;
    if(i <= 4)
    {
        cout<<"*"<<endl;
        i++;
    }
}

int main()
{
    Display();

    return 0;
}